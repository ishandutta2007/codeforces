#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=200005;
vector<PI> f[N],g[N];
vector<int> e[N];
int col[N],x[N],y[N];
int F[N],G[N];
void solve(vector<PI> &v){
	sort(v.begin(),v.end());
	for(unsigned i=0;i+1<v.size();i+=2){
		e[v[i].se].pb(v[i+1].se);
		e[v[i+1].se].pb(v[i].se);
	}
}
void dfs(int p,int x){
	if(col[p])return; else col[p]=x;
	for(auto i:e[p])dfs(i,3-x);
}
int main(){
	int n=read();
	For(i,1,n){
		x[i]=read(),y[i]=read();
		f[x[i]].pb(mp(y[i],i));
		g[y[i]].pb(mp(x[i],i));
	}
	For(i,1,200000){
		solve(f[i]);
		solve(g[i]);
	}
	
	For(i,1,n){if(!col[i])dfs(i,1); putchar(col[i]==1?'r':'b');}
	For(i,1,n)if(col[i]==1){
		F[x[i]]++; G[y[i]]++;
	}else{
		F[x[i]]--; G[y[i]]--;
	}
}