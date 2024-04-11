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
ll ans1,ans2;
int n,sz[N];
vector<PI> v[N];
void dfs(int p,int fa,ll jj){
	sz[p]=1;
	for(auto i:v[p])if(i.fi!=fa){
		dfs(i.fi,p,i.se);
		sz[p]+=sz[i.fi];
	}
	ans1+=(sz[p]&1)*jj;
	ans2+=min(sz[p],n-sz[p])*jj;
	//cout<<sz[p]<<endl;
}
int main(){
	int T=read();
	while(T--){
		n=read()*2; ans1=ans2=0;
		For(i,1,n)v[i].clear();
		For(i,1,n-1){
			int s=read(),t=read(),c=read();
			v[s].pb(mp(t,c)); v[t].pb(mp(s,c));
		}
		dfs(1,0,0);
		cout<<ans1<<" "<<ans2<<endl;
	}
}