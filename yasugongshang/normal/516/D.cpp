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
const int N=100005;
int fa[N],ans[N],s;
ll dis[N];
vector<PI> v[N];
pair<ll,int> jb[N];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
void dfs(int p,int fa){
	if(dis[p]>dis[s])s=p;
	//cout<<p<<endl;
	for(auto i:v[p]){
		if(i.fi==fa)continue;
		dis[i.fi]=dis[p]+i.se;
		dfs(i.fi,p);
	}
}
int main(){
	int n=read();
	For(i,1,n-1){
		int s=read(),t=read(),x=read();
		v[s].pb(mp(t,x));
		v[t].pb(mp(s,x));
	}
	dfs(1,0);
	int rt=s; dis[rt]=s=0;
	dfs(rt,0);
	For(i,1,n)jb[i].fi=dis[jb[i].se=i];
	rt=s; dis[rt]=s=0;
	//cout<<rt<<" "<<dis[5]<<endl;
	dis[rt]=0; dfs(rt,0);
	For(i,1,n)jb[i].fi=max(jb[i].fi,dis[i]);
	//For(i,1,n)wri(jb[i].fi);
	sort(jb+1,jb+n+1); 
	int q=read();
	while(q--){
		ll x=read();
		int dq=n,an=0;
		mem(ans);
		
		For(i,1,n)fa[i]=i;
		Rep(i,n,1){
			while(dq&&jb[i].fi-jb[dq].fi<=x){
				int id=jb[dq--].se;
				ans[id]=1; //cout<<id<<" "<<endl;
				for(auto j:v[id]){
					int jj=gf(j.fi); if(!ans[jj])continue;
				//cout<<an<<" fjz "<<i<<" "<<id<<" "<<jj<<" "<<ans[id]<<" "<<jb[i].fi<<" "<<jb[dq+1].fi<<endl;
					ans[id]+=ans[jj]; fa[jj]=id;
				}
				an=max(an,ans[id]);
			}
			//cout<<dq<<" "<<i<<" "<<an<<" "<<gf(jb[i].se)<<endl;
			ans[gf(jb[i].se)]--;
		}
		writeln(an);
	}
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
1
2

*/