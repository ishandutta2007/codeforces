#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
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
const int N=1005;
int dep[N],fa[N],vis[N],jb;
vector<int> v[N];
void dfs(int p){
	dep[p]=dep[fa[p]]+1;
	if(dep[p]>dep[jb])jb=p;
	for(auto i:v[p])if(!vis[i]&&i!=fa[p]){
		fa[i]=p;
		dfs(i);
	}
}
int main(){
	int n=read();
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	int rt=1;
	while(1){
		jb=fa[rt]=0;
		dfs(rt);
		int t=jb; fa[t]=jb=0;	
		dfs(t);
		if(t==rt&&jb==rt){
			cout<<"! "<<rt<<endl; return 0;
		}
		cout<<"? "<<t<<" "<<jb<<endl;
		rt=read();
		for(int i=fa[rt];i;i=fa[i])vis[i]=1;
		for(int i=jb;i!=rt;i=fa[i])vis[i]=1;
	}
}