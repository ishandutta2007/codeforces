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
int k,t;
int ans,X[10][100],Y[10][100],x[100],y[100];
void solve(int p,vector<poly> v){
	if(!p){
		ans+=v[0][0]>0; return;
	}
	int n=1<<p;
	vector<poly> vv(n); 
	For(i,0,n-1)vv[i].resize(n);
	For(i,0,n-1){
		For(j,0,n-1){
			For(k,1,t){
				vv[(i+X[p][k])%n][(j+Y[p][k])%n]^=v[i][j];
			}
		}
	}
	vector<poly> V[2][2];
	For(i,0,1)For(j,0,1){
		V[i][j].resize(n/2);
		For(k,0,n/2-1)V[i][j][k].resize(n/2);
	}
	For(i,0,n-1)For(j,0,n-1)V[i&1][j&1][i/2][j/2]=vv[i][j];
	For(i,0,1)For(j,0,1)solve(p-1,V[i][j]);
}
int main(){
	k=read();
	vector<poly> v;
	For(i,0,(1<<k)-1){
		poly zs(1<<k);
		For(j,0,(1<<k)-1)zs[j]=read();
		v.pb(zs);
	}
	t=read();
	For(i,1,t){
		x[i]=read(); y[i]=read();
	}
	int n=1<<k;
	Rep(i,t,1){X[k][i]=(x[i]-x[1]+n)%n; Y[k][i]=(y[i]-y[1]+n)%n;}
	Rep(i,k-1,0){
		For(j,1,t)X[i][j]=(X[i+1][j]<<1)%(1<<(i+1))/2,Y[i][j]=(Y[i+1][j]<<1)%(1<<(i+1))/2;
	}
	solve(k,v);
	cout<<ans<<endl;
}