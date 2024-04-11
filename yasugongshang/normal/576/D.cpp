#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int N=155,inf=1e9+1e7;
int dis[N][N],n,m,ans=inf;
pair<int,PI> q[N];
bitset<N> dq[N],zs[N];
void mer(bitset<N> a[N],bitset<N> b[N],bitset<N> c[N]){
	static bitset<N> d[N];
	For(i,0,N-1)d[i]=0;
	For(k,1,n){
		For(i,1,n)if(a[i][k])d[i]|=b[k];
	}
	For(i,0,N-1)swap(d[i],c[i]);
}
void ksm(bitset<N> dq[N],bitset<N> zs[N],int k){
	static bitset<N> z[N];
	For(i,0,N-1)z[i]=zs[i];
	for(;k;k>>=1){
		if(k&1){
			mer(dq,z,dq);
		}
		mer(z,z,z);
	}
}
int main(){
	n=read(),m=read();
	For(i,1,m){
		q[i].se.fi=read(); q[i].se.se=read();
		q[i].fi=read();
	}
	sort(q+1,q+m+1);
	For(i,1,n)For(j,1,n)if(i!=j)dis[i][j]=inf;
	For(i,1,n){dq[i][i]=1;}
	For(i,1,m){
		int d=q[i].fi,x=q[i].se.fi,y=q[i].se.se;
		ksm(dq,zs,d-q[i-1].fi);
		zs[x][y]=1;
		For(j,1,n)For(k,1,n)dis[j][k]=min(dis[j][x]+dis[y][k]+1,dis[j][k]);
		//cout<<dis[1][n]<<" "<<dq[1][2]<<" "<<d<<" "<<ans<<endl;
		For(j,1,n)if(dq[1][j])ans=min(ans,d+dis[j][n]);
	}
	if(ans==inf)puts("Impossible"); else cout<<ans<<endl;
}