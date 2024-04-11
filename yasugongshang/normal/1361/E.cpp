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
const int  N=100005,inf=1e9;
vector<int> v[N],e[N];
bitset<N> zh,vis,vi;
int f,rt,dep[N],q[N];
PI fz[N];
bool cmp(int x,int y){
	return dep[x]<dep[y];
}
int Min(int x,int y){
	return cmp(x,y)?x:y;
}
PI operator +(PI a,PI b){
	if(cmp(a.fi,b.fi))return mp(a.fi,Min(a.se,b.fi));
	else return mp(b.fi,Min(a.fi,b.se));
}
void dfs(int p){
	if(!f)return;
	zh[p]=vis[p]=1; 
	fz[p]=mp(p,0);
	for(auto i:v[p])if(vis[i]){
		fz[p]=fz[p]+mp(i,0);
		if(!zh[i])f=0;
	}else{
		dep[i]=dep[p]+1;
		dfs(i);
		fz[p]=fz[p]+fz[i];
	}
	zh[p]=0;
}
void ddd(int p){
	if(vi[p])return; else vi[p]=1;
	for(auto i:e[p])ddd(i);
}
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	dep[0]=inf;
	int T=read();
	while(T--){
		int n=read(),m=read();
		For(i,1,n){v[i].clear(); e[i].clear(); vi[i]=0;}
		For(i,1,m){
			int s=read(),t=read();
			v[s].pb(t); //e[t].pb(s);
		}
		vector<int> ans;
		For(i,1,200){
			For(i,1,n)vis[i]=0; f=1;
			int t=rt=rnd()%n+1;
			dep[t]=0;
			dfs(t);
			if(f){
				//ddd(t);
				//cout<<t<<endl; For(i,1,n)wri(fz[i].se); puts("");
				For(i,1,n)vi[q[i]=i]=1;
				sort(q+1,q+n+1,cmp);
				For(i,1,n){
					int x=q[i];
					if(dep[fz[x].se]<dep[x]||!vi[fz[x].fi])vi[x]=0;
					//cout<<x<<" "<<vi[x]<<" "<<fz[x].fi<<" "<<fz[x].se<<endl;
				}
				For(i,1,n)if(vi[i]==1)ans.pb(i);
				break;
			}
		}
		if(ans.size()*5<n)puts("-1");
		else {
			for(auto i:ans)wri(i); puts("");
		}
	}
	
}