#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define y1 zyyakking
#define PI pair<int,int>
#define poly vector<int>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
#define PB pop_back
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
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=500005;
vector<PI> ans;
vector<int> v[N],jb[N];
int n,m,rt,dep[N],fa[N],vis[N];
void dfs(int p){
	if(rt)return;
	dep[p]=dep[fa[p]]+1; vis[p]=1;
	if(dep[p]>=(n+1)/2){
		rt=p; return;
	}
	for(auto i:v[p])if(!vis[i]){
		fa[i]=p; dfs(i);
		//cout<<p<<" edge "<<i<<endl;
		while(jb[p].size()&&jb[i].size()){
			//cerr<<p<<" fj "<<i<<" "<<jb[p].back()<<endl;;
			ans.pb(mp(jb[p].back(),jb[i].back()));
			jb[p].PB(); jb[i].PB();
		}
		if(jb[i].size())swap(jb[p],jb[i]);
	}
	//cout<<p<<endl;
	jb[p].pb(p);
}
int main(){
	#ifdef Brollan
        freopen("1.in","r",stdin);
    #endif
    int T=read();
    while(T--){
    	n=read(); m=read(); rt=0;
    	ans.clear();
    	For(i,1,n){v[i].clear(); jb[i].clear(); vis[i]=0;}
		For(i,1,m){
			int s=read(),t=read();
			v[s].pb(t); v[t].pb(s);
		}
		dfs(1);
		if(rt){
			vector<int> an;
			for(int i=rt;i;i=fa[i])an.pb(i);
			puts("PATH");
			writeln(an.size());
			for(auto i:an)wri(i); puts("");
		}else{
			puts("PAIRING");
			writeln(ans.size());
			for(auto i:ans){
				wri(i.fi); writeln(i.se);
			}
		}
	}
}