#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int mod=1e9+7,N=105,M=905;
int a[N],b[N],A[N][M],B[N][M],p[M],n,m,id,k;
int vis[M];
ll ksm(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void GG(ll x){
	if(x)return;
	puts("-1"); exit(0);
}
void fj(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0){
		p[++m]=i; while(x%i==0)x/=i;
	}
	if(x>1)p[++m]=x;
}
void FJ(){
	For(i,1,n){
		int aa=a[i],bb=b[i];
		For(j,1,m){
			while(aa%p[j]==0){A[i][j]++; aa/=p[j];}
			while(bb%p[j]==0){B[i][j]++; bb/=p[j];}
		}
	}
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=a; y=0; return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
void check(){
	For(i,1,n)if(i!=k){
		int lst=-1;
		For(j,1,m)if(!B[i][j]){
			GG(A[i][j]==B[id][j]*k+A[id][j]);
		}else{
			int fz=(k*B[id][j]+A[id][j]-A[i][j]),fm=B[i][j];
			GG(fz>=0&&fz%fm==0);
			int kk=fz/fm; if(lst>=0)GG(lst==kk); else lst=kk;
		}
	}
	//cout<<id<<" "<<k<<" "<<a[1]<<" "<<b[1]<<endl;
	cout<<a[id]*ksm(b[id],k)%mod<<endl; exit(0);
}
int main(){
	n=read();
	For(i,1,n){
		a[i]=read(); b[i]=read();
		fj(a[i]); fj(b[i]);
	}
	FJ();
	For(i,1,m){
		int f=0,g=0;
		For(j,1,n)if(!B[j][i])f=j; else if(B[j][i])g=j; 
		if(f){
			if(!g){
				For(j,2,n)GG(A[j][i]==A[1][i]); 
			}else{
				GG((A[f][i]-A[g][i])%B[g][i]==0);
				id=g; k=(A[f][i]-A[g][i])/B[g][i]; GG(k>=0); break;
			}
		}else vis[i]=1;
	}
	if(id)check();
	int mm=0; For(i,1,m)if(vis[i])p[++mm]=p[i]; m=mm;
	if(!mm){
		cout<<a[1]<<endl; return 0;
	}
	
	memset(A,0,sizeof(A)); memset(B,0,sizeof(B));
	FJ();
	For(i,1,n){
		For(j,2,m)if(B[1][1]*B[i][j]!=B[i][1]*B[1][j]){
			int fm=B[1][1]*B[i][j]-B[1][j]*B[i][1],fz=(A[i][1]-A[1][1])*B[i][j]-(A[i][j]-A[1][j])*B[i][1];
			GG(fz%fm==0);
			id=1; k=fz/fm; GG(k>=0); check(); break;
		}else {
			//cout<<i<<" "<<j<<" "<<A[1][1]<<" "<<A[i][1]<<" "<<B[1][j]<<" "<<A[1][j]<<" "<<A[i][j]<< " "<<B[i][j]<<endl;
			GG((A[1][1]-A[i][1])*B[i][j]==(A[1][j]-A[i][j])*B[i][1]);
		}
	}
	ll ans1=1,ans2=0;
	For(i,1,n){
		ll u=B[i][1],v=A[i][1]%B[i][1],x,y;
		ll t=__gcd(u,ans1); u/=t; ans1/=t; GG((ans2-v)%t==0);
		exgcd(u,ans1,x,y); y=-y;
		ll n1=ans1*u*t,n2=((ans2-v)/t%u*y%u*ans1*t+ans2)%n1;
		ans1=n1; ans2=n2;
		//cout<<ans1<<" "<<ans2<<" "<<u<<" "<<v<<" "<<x<<" "<<y<<endl;
	}
	ans2=(ans2+ans1)%ans1;
	For(i,1,n)if(A[i][1]>ans2)ans2=ans2+(A[i][1]-ans2+ans1-1)/ans1*ans1;
	cout<<a[1]*ksm(b[1],(ans2-A[1][1])/B[1][1])%mod<<endl;
}
/*
30
1 2
2 2
4 2
8 2
16 2
32 2
64 2
128 2
256 2
512 2
1024 2
2048 2
4096 2
8192 2
16384 2
32768 2
65536 2
131072 2
262144 2
524288 2
1048576 2
2097152 2
4194304 2
8388608 2
16777216 2
33554432 2
67108864 2
536870912 4
134217728 16
536870912 2

*/