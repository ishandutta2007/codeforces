#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
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
int n,rt,sz[N],f[N],dq,de,jb[N];
vector<int> v[N];
bool cmp(int a,int b){
	return sz[a]<sz[b];
}
void dfs(int p,int fa){
	sz[p]=1;
	for(auto i:v[p])if(i!=fa){dfs(i,p); sz[p]+=sz[i]; f[p]=max(f[p],sz[i]);}
	f[p]=max(f[p],n-sz[p]);
	if(f[p]<f[rt])rt=p;
}
void Dfs(int p,int fa){
	dq+=de;
	jb[p]=dq;
	wri(p); wri(fa); writeln(jb[p]-jb[fa]);
	for(auto i:v[p])if(i!=fa)Dfs(i,p);
}
int main(){
	n=read(); f[0]=1e9;
	if(n==1)return 0;
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	dfs(1,0);
	for(auto i:v[rt])if(sz[i]>sz[rt])sz[i]=n-sz[rt];
	sort(v[rt].begin(),v[rt].end(),cmp);
	sz[v[rt][0]]++;
	int jj=0;
	For(i,0,v[rt].size()-1){
		jj+=sz[v[rt][i]];
		//cout<<jj<<" "<<rt<<" "<<f[rt]<<endl;
		if(jj*(n-jj)>=n*n*2/9){
			de=n-jj+1; dq=0;
			For(j,0,i)Dfs(v[rt][j],rt);
			de=1; dq=0;
			For(j,i+1,v[rt].size()-1)Dfs(v[rt][j],rt);
			return 0;
		}
	}
}