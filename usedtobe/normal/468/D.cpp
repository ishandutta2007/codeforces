#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#define mp make_pair
#define pii pair<int,int>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define re(i,u) for (int i=H[u];i;i=nxt[i])
#define X first
#define Y second
#define N 500005
using namespace std;
typedef long long ll;
int sub[N],dis[N],to[N],H[N],anc[N],size[N],Cnt,cnt,nxt[N],n,Anc[N],res[N],num[N]; ll ans;
set<pii,greater<pii > > SZ;
set<int> S[N];set<pii > T;set<pii >::iterator it;
void ins(int x,int y,int z) {to[++cnt]=y;dis[cnt]=z;nxt[cnt]=H[x];H[x]=cnt;}
void center(int u,int fa) {
	size[u]=1;int v;
	re(i,u) if ((v=to[i])!=fa){
		center(v,u);
		size[u]+=size[v];
		sub[u]=max(sub[u],size[v]);
	}
	sub[u]=max(sub[u],n-size[u]);
}
void dfs(int u,int fa,int anc) {
	size[u]=1;Anc[u]=anc;if(anc)S[anc].insert(u);int v;
	re(i,u) if ((v=to[i])!=fa) {
		(!anc)?dfs(v,u,++Cnt):dfs(v,u,anc);
		size[u]+=size[v];ans+=2ll*dis[i]*size[v];
	}
}
void link(int x,int y){
	int p=*S[y].begin();res[x]=p;T.erase(mp(p,y));SZ.erase(mp(num[y],y));
	if(x!=p)SZ.erase(mp(num[Anc[x]],Anc[x]));S[y].erase(p);
	num[Anc[x]]--;num[y]--;
	if (S[y].size()) T.insert(mp(*S[y].begin(),y));
	if(x!=p)SZ.insert(mp(num[y],y));SZ.insert(mp(num[Anc[x]],Anc[x]));
}
void work(int rt) {
	dfs(rt,0,0);S[0].insert(rt);rep(i,1,Cnt)T.insert(mp(*S[i].begin(),i));T.insert(mp(rt,0));
	rep(i,0,Cnt)SZ.insert(mp(num[i]=S[i].size()*2,i));int now=n;
	rep(i,1,n) {
		if (SZ.begin()->X==now--&&Anc[i]!=SZ.begin()->Y&&SZ.begin()->Y!=0) {link(i,SZ.begin()->Y);continue;}
		it=T.begin();if (i!=rt&&it->Y==Anc[i]) it++;
		link(i,it->Y);
	}
	cout<<ans<<endl;
	rep(i,1,n)printf("%d%c",res[i],i==n?'\n':' ');
}
int main() {
	scanf("%d",&n);rep(i,1,n-1){int u,v,w;scanf("%d%d%d",&u,&v,&w);ins(u,v,w);ins(v,u,w);}
	center(1,0);rep(i,1,n)if(sub[i]<=n/2)return work(i),0;
	return 0;
}