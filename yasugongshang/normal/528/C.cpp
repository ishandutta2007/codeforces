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
const int N=100005,M=500005;
vector<PI> ans;
int rd[N],d[N],ne=1,vis[N],son[N],ed[M],nxt[M],vv[M];
vector<int> v;
void dfs(int p,int fa){
	vis[p]=1; 
	for(int i=son[p];i;i=nxt[i])if(i!=fa){
		if(vis[ed[i]]){if(!vv[i]){rd[ed[i]]++; ans.pb(mp(p,ed[i])); vv[i]=vv[i^1]=1;} continue;}
		dfs(ed[i],i^1);
		if(rd[ed[i]]&1){
			ans.pb(mp(p,ed[i]));
		}else {
			ans.pb(mp(ed[i],p)); rd[p]^=1;
		}
	}
}
void ae(int a,int b){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b; d[a]++;
}
int main(){
	int n=read(),m=read();
	For(i,1,m){
		int s=read(),t=read();
		ae(s,t); ae(t,s);
	}
	For(i,1,n)if(d[i]&1)v.pb(i);
	int s=m;
	for(unsigned i=0;i<v.size();i+=2){
		ans.pb(mp(v[i],v[i+1])); rd[v[i+1]]++; s++;
	}
	if(s&1)ans.pb(mp(1,1));
	dfs(1,0);
	writeln(ans.size());
	for(auto i:ans){wri(i.fi); writeln(i.se);}
	
}
/*
4 6
1 2
2 3
3 4
4 1
1 3
1 3

*/