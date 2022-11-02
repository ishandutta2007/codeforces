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
const int N=150005,M=40000000,K=18;
int ls[M],rs[M],tr[M];
int qj,n,m,k,ti,nodecnt,q[N<<2],dep[N],rt[N],in[N],out[N],dp[N][K];
vector<int> v[N],zs[N],jb[N];
vector<pair<int,int> > e[N];
ll ans;
bool cmp(int a,int b){
	return in[a]<in[b];
}
bool zx(int a,int b){
	return in[a]<=in[b]&&out[a]>=out[b];
}
int lca(int a,int b){
	if(zx(a,b))return a;
	Rep(i,K-1,0)if(dp[a][i]&&!zx(dp[a][i],b))a=dp[a][i];
	return dp[a][0];
}
int get(int a,int k){
	Rep(i,K-1,0)if(k>>i&1)a=dp[a][i];
	return a;
}
int ask(int l,int r,int i,int j,int nod){
	if(!nod||i>r||j<l)return 0;
	if(i<=l&&r<=j)return tr[nod];
	int mid=(l+r)>>1;
	return ask(l,mid,i,j,ls[nod])+ask(mid+1,r,i,j,rs[nod]);
}
void ins(int l,int r,int pos,int de,int &nod){
	if(!nod)nod=++nodecnt;
	tr[nod]+=de;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(pos<=mid)ins(l,mid,pos,de,ls[nod]); else ins(mid+1,r,pos,de,rs[nod]);
}
int mer(int a,int b){
	if(!a||!b)return a|b;
	ls[a]=mer(ls[a],ls[b]);
	rs[a]=mer(rs[a],rs[b]);
	tr[a]+=tr[b];
	return a;
}
void bao(int x){//cout<<in[x]<<" "<<x<<" fjzzq\n";
	ins(1,n,in[x],1,rt[0]); if(out[x]<n)ins(1,n,out[x]+1,-1,rt[0]);
}
void dfs(int p,int fa){
	for(auto i:v[p])if(i!=fa){
		dfs(i,p);
	}
	for(auto i:e[p]){
		ans+=ask(1,n,1,in[i.fi],rt[0])+ask(1,n,1,in[i.se],rt[0]);
	//cout<<p<<" "<<ans<<" "<<tr[rt[0]]<<" "<<ask(1,n,1,1,rt[0])<<endl;
	}
	for(auto i:e[p]){
		if(dep[i.fi]>=dep[p]+k)bao(get(i.fi,dep[i.fi]-dep[p]-k));
		if(dep[i.se]>=dep[p]+k)bao(get(i.se,dep[i.se]-dep[p]-k));
	}
}
void ins(int p,int j){
	if(dep[p]-dep[qj]>=k){
		if(j==qj)ans+=tr[rt[p]]*2; else{
			int bro=get(j,dep[j]-dep[qj]-1);
			ans+=tr[rt[p]]*2-ask(1,n,in[bro],out[bro],rt[p]);			
		}
	}else{
		int bro=get(j,dep[j]-dep[qj]-(k-dep[p]+dep[qj]));
		ans+=ask(1,n,in[bro],out[bro],rt[p]);
	}
	jb[p].pb(j);
}
void solve(int p){
	for(auto i:zs[p]){
		solve(i);
		if(p!=qj){
			if(jb[i].size()>jb[p].size()){
				swap(jb[p],jb[i]);
				swap(rt[p],rt[i]);
			}
			for(auto j:jb[i])ins(p,j); 
			rt[p]=mer(rt[p],rt[i]);
		}
	}
}
void init(int p,int fa){
	dp[p][0]=fa; in[p]=++ti; dep[p]=dep[fa]+1;
	for(auto i:v[p])if(i!=fa)init(i,p);
	out[p]=ti;
}
int main(){
	
	n=read(),m=read(),k=read();
	For(i,1,n-1){
		int s=read(),t=read();
		v[s].pb(t); v[t].pb(s);
	}
	init(1,0);
	For(i,1,K-1)For(j,1,n)dp[j][i]=dp[dp[j][i-1]][i-1];
	For(i,1,m){
		int s=read(),t=read(),x=lca(s,t);
		if(dep[s]+dep[t]-2*dep[x]<k)continue;
		e[x].pb(mp(s,t));
	}
	dfs(1,0); 
	ans*=2; 
	For(o,1,n){
		qj=o;
		int tt=0;
		for(auto i:e[o]){
			q[++tt]=i.fi; q[++tt]=i.se;
		}
		sort(q+1,q+tt+1,cmp);
		Rep(i,tt-1,1)q[++tt]=lca(q[i],q[i+1]);
		sort(q+1,q+tt+1,cmp); tt=unique(q+1,q+tt+1)-q-1;
		stack<int> st; st.push(q[1]);
		For(i,2,tt){
			while(!zx(st.top(),q[i]))st.pop();
			zs[st.top()].pb(q[i]); st.push(q[i]);
		}
		for(auto i:e[o]){
			if(i.fi!=o){ins(i.fi,i.se); ins(1,n,in[i.se],1,rt[i.fi]);}
			if(i.se!=o){ins(i.se,i.fi); ins(1,n,in[i.fi],1,rt[i.se]);}
		}
		solve(o);
		For(i,1,nodecnt)ls[i]=rs[i]=tr[i]=0;
		nodecnt=0;
		For(i,1,tt){
			int x=q[i];
			jb[x].clear(); rt[x]=0; zs[x].clear();
		}
	}
	cout<<ans/2<<endl;
}
/*

*/