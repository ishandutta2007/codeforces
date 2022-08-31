#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a,b,tot,fl,len,ncnt;
int dep[100005],f[100005],v[200005],nxt[200005],h[100005],mx1[100005],mx2[100005],tmx[100005],cnt[100005],r[100005];
bool vis[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]]=u;
		dfs1(v[p],u);
	}
}

int lca(int x,int y){
	int res=0;
	while(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		vis[x]=1;
		res++,x=f[x];
	}
	vis[x]=1;
	return res;
}

void dfs2(int u,int fa){
	mx1[u]=mx2[u]=tmx[u]=cnt[u]=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs2(v[p],u);
		if(mx1[v[p]]+1>=len) cnt[u]++;
		if(mx1[v[p]]+1>mx1[u]) mx2[u]=mx1[u],mx1[u]=mx1[v[p]]+1;
		else chkmax(mx2[u],mx1[v[p]]+1);
	}
}

void dfs3(int u,int fa){
	if(tmx[u]>=len) cnt[u]++;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(mx1[u]==mx1[v[p]]+1) tmx[v[p]]=max(tmx[u],mx2[u])+1;
		else tmx[v[p]]=max(tmx[u],mx1[u])+1;
		dfs3(v[p],u);
	}
}

void dfs4(int u,int fa){
	mx1[u]=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||vis[v[p]]) continue;
		dfs4(v[p],u);
		chkmax(mx1[u],mx1[v[p]]+1);
	}
}

void dfs5(int u,int fa){
	r[++ncnt]=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||!vis[v[p]]) continue;
		dfs5(v[p],u);
	}
}

void dfs6(int u,int fa){
	if(cnt[u]>=3) fl=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||vis[v[p]]) continue;
		dfs6(v[p],u);
	}
}

int main(){
	int T=readint();
	while(T--){
		fl=0;
		n=readint(); a=readint(); b=readint();
		for(int i=1;i<=n;i++) h[i]=vis[i]=0; tot=ncnt=0;
		for(int i=1;i<n;i++) addedge(readint(),readint());
		dep[1]=1; dfs1(1,-1);
		len=lca(a,b);
		dfs2(1,-1);
		dfs3(1,-1);
		for(int i=1;i<=n;i++) if(vis[i]) dfs4(i,-1);
		dfs5(a,-1);
		int lstl=1,nowl=1,lstr=ncnt,nowr=ncnt;
		while(lstl<=nowl||lstr>=nowr){
			for(int j=lstl;j<=nowl;j++) chkmin(nowr,ncnt-mx1[r[j]]+j-1);
			chkmax(nowr,1);
			lstl=nowl+1;
			for(int j=lstr;j>=nowr;j--) chkmax(nowl,mx1[r[j]]-ncnt+j+1);
			chkmin(nowl,ncnt);
			lstr=nowr-1;
		}
		for(int i=1;i<=nowl;i++) dfs6(r[i],-1);
		for(int i=nowr;i<=ncnt;i++) dfs6(r[i],-1);
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}