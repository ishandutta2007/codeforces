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
#define SZ(x) ((int)(x.size()))
#define re resize
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
const int N=100005;
int sz[N],mx[N],ans[N],n,lst;
vector<int> v[N],V[N],zx;
void dfs(int p,int fa){
	sz[p]=1; 
	for(auto i:v[p])if(i!=fa){
		dfs(i,p);
		sz[p]+=sz[i];
		mx[p]=max(mx[p],sz[i]);
	}
	mx[p]=max(mx[p],n-sz[p]);
	if(mx[p]*2<=n)zx.pb(p);
}
ll tt;
int rt;
void solve(int p,int fa,int dep){
	tt+=dep; V[rt].pb(p);
	for(auto i:v[p])if(i!=fa)solve(i,p,dep+2);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	
	dfs(1,0);
	vector<int> an;
	priority_queue<PI> q;
	if(zx.size()==1){
		int x=zx[0];
		for(auto i:v[x]){
			rt=i; solve(i,x,2); q.push(mp(V[i].size(),i));
		}
		an.pb(x); lst=0;
	}else{
		int x=zx[0],y=zx[1];
		rt=x; solve(x,y,1); q.push(mp(V[x].size(),x));
		rt=y; solve(y,x,1); q.push(mp(V[y].size(),y));
	}
	while(q.size()){
		PI alb=mp(0,0); 
		if(q.top().se==lst){
			alb=q.top(); q.pop();
		}
		int t=q.top().se;
		q.pop();
		an.pb(V[t].back()); lst=t; V[t].pop_back();
		if(V[t].size())q.push(mp(V[t].size(),t));
		if(alb.fi)q.push(alb);
	}
	For(i,0,an.size()-1)ans[an[i]]=an[(i+1)%an.size()];
	writeln(tt);
	For(i,1,n)wri(ans[i]);
}