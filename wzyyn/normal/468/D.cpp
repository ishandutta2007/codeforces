#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],n,tot;
int sz[N],mxv,rt;
int co[N],sz1[N],sz2[N],mat[N];
set<int> S[N];
set<pii> SS,SSS;
ll ans;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs(int x,int fa){
	sz[x]=1;
	int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
			ans+=2ll*min(sz[e[i].to],n-sz[e[i].to])*e[i].v;
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,rt=x;
}
void color(int x,int fa,int c){
	co[x]=c;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			color(e[i].to,x,c);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	mxv=1<<30;
	dfs(1,0);
	printf("%lld\n",ans);
	co[rt]=rt;
	for (int i=head[rt];i;i=e[i].next)
		color(e[i].to,rt,e[i].to);
	For(i,1,n) S[co[i]].insert(i);
	For(i,1,n) S[i].insert(1<<30);
	For(i,1,n) ++sz1[co[i]],++sz2[co[i]]; --sz2[rt];
	For(i,1,n) if (co[i]==i) SS.insert(pii(*S[i].begin(),i));
	For(i,1,n) if (co[i]==i) SSS.insert(pii(sz1[i]+sz2[i],i));
	For(i,1,n){
		int be=co[i];
		SSS.erase(pii(sz1[be]+sz2[be],be));
		--sz1[be];
		SSS.insert(pii(sz1[be]+sz2[be],be));
		int id;
		if (SSS.rbegin()->fi==n-i+1) id=SSS.rbegin()->se;
		else{
			set<pii>::iterator it=SS.begin();
			if (it->se==be&&i!=rt) ++it;
			id=it->se;
		}
		mat[i]=*S[id].begin();
		SS.erase(pii(*S[id].begin(),id));
		S[id].erase(S[id].begin());
		SS.insert(pii(*S[id].begin(),id));
		SSS.erase(pii(sz1[id]+sz2[id],id));
		--sz2[id];
		SSS.insert(pii(sz1[id]+sz2[id],id));
	}
	For(i,1,n) printf("%d ",mat[i]);
	puts("");
}