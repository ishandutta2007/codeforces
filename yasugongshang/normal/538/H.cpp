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
const int N=100005,inf=1e9;
int col[N],l[N],r[N];
bool vis[N];
vector<int> v[N];
void GG(){
	puts("IMPOSSIBLE"); exit(0);
}
void dfs(int p,int co){
	if(col[p]>=0&&col[p]!=co)GG();
	col[p]=co; vis[p]=1;
	for(auto i:v[p])if(!vis[i])dfs(i,co^1); else if(col[i]==col[p])GG();
}
bool in(int x,int l,int r){
	return x>=l&&x<=r;
}
int main(){
	int t=read(),T=read(),n1=-inf,n2=inf;
	int n=read(),m=read();
	For(i,1,n){
		n1=max(n1,l[i]=read());
		n2=min(n2,r[i]=read());
	}
	if(n1+n2>T)n2=T-n1;
	if(n1+n2<t)n1=t-n2;
	if(n1<0||n2<0)GG();
	For(i,1,n)if(in(n1,l[i],r[i])&&in(n2,l[i],r[i]))col[i]=-1;
	else if(in(n1,l[i],r[i]))col[i]=0;
	else if(in(n2,l[i],r[i]))col[i]=1;
	else GG();
	For(i,1,m){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	For(i,1,n)if(!vis[i]&&col[i]>=0)dfs(i,col[i]);
	For(i,1,n)if(!vis[i])dfs(i,0);
	puts("POSSIBLE");
	wri(n1); writeln(n2);
	For(i,1,n)write(col[i]+1);
}