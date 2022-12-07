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
const int B=355;
const int N=200005;
vector<int> e[N];
int n,Q,fa[N],lim[N],qv[N];
int dfn[N],ed[N],dep[N],top[N],sz[N];
int q[N],qq[N],vis[N],f[N];
int id[N],Fa[N],stk[N];
int g[1005][1005],pos[1005];
void dfs(int x){
	sz[x]=1;
	dep[x]=max(dep[x],1);
	for (auto i:e[x]){
		dep[i]=dep[x]+1; dfs(i);
		sz[x]+=sz[i];
	}
}
void dfs(int x,int tp){
	dfn[x]=++*dfn;
	top[x]=tp;
	int k=0;
	for (auto i:e[x])
		if (sz[i]>sz[k])
			k=i;
	if (k) dfs(k,tp);
	for (auto i:e[x])
		if (i!=k)
			dfs(i,i);
	ed[x]=*dfn;
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	For(i,2,n) scanf("%d",&fa[i]);
	For(i,2,n) e[fa[i]].PB(i);
	For(i,1,n) scanf("%d",&lim[i]);
	For(i,1,Q) scanf("%d",&qv[i]);
	dfs(1); dfs(1,1); q[++*q]=1;  
	For(i,1,n) for (auto j:e[q[i]]) q[++*q]=j;
	//For(i,1,n) cout<<q[i]<<' '; cout<<endl;
	for (int l=1,r=B;l<=Q;l+=B,r+=B){
		int ans=0; r=min(r,Q);
		For(j,1,n) vis[j]=0;
		For(j,1,l-1) vis[abs(qv[j])]^=1;
		For(j,1,n) f[j]=(vis[j]?1:0);
		Rep(j,n,1) f[fa[q[j]]]+=f[q[j]];
		For(j,1,n) ans+=(!vis[j]&&f[j]>lim[j]);
		*qq=0;
		For(j,l,r) qq[++*qq]=abs(qv[j]);
		sort(qq+1,qq+*qq+1,cmp);
		For(j,1,(*qq)-1) qq[j+(*qq)]=LCA(qq[j],qq[j+1]);
		sort(qq+1,qq+2*(*qq),cmp);
		*qq=unique(qq+1,qq+2**qq)-qq-1;
		For(j,1,*qq) id[qq[j]]=j;
		int top=1; stk[1]=qq[1]; Fa[qq[1]]=0;
		For(j,2,*qq){
			for (;top&&!isfa(stk[top],qq[j]);top--);
			Fa[qq[j]]=stk[top];
			stk[++top]=qq[j];
		}
		For(j,1,*qq){
			memset(g[j],0,sizeof(g[j]));
			int x=qq[j],y=Fa[qq[j]];
			pos[j]=B;
			for (x=fa[x];dep[x]>dep[y];x=fa[x])
				if (!vis[x]){
					int v=f[x]-lim[x];
					if (v>=-B&&v<=B) ++g[j][v+B];
				}
		}
		For(j,l,r){
			int p=abs(qv[j]);
			int v=(qv[j]<0?-1:1);
			for (;p;p=Fa[p]){
				ans-=(!vis[p]&&f[p]>lim[p]);
				if (p==abs(qv[j])) vis[p]^=1; f[p]+=v;
				ans+=(!vis[p]&&f[p]>lim[p]);
				if (v==1) ans+=g[id[p]][pos[id[p]]--];
				else ans-=g[id[p]][++pos[id[p]]];
			}
			printf("%d ",ans);
		}
	}
}