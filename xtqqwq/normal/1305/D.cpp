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

int n,tot,optx,opty,nowmax;
int v[2005],nxt[2005],h[1005],f[1005],dep[1005];
bool vis[1005];
pii max1[1005],max2[1005];

int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	max1[u]=max2[u]=mp(0,u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||vis[v[p]]) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		if(max1[v[p]].fi+1>max1[u].fi) max2[u]=max1[u],max1[u]=mp(max1[v[p]].fi+1,max1[v[p]].se);
		else if(max1[v[p]].fi+1>max2[u].fi) max2[u]=mp(max1[v[p]].fi+1,max1[v[p]].se);
	}
	if(chkmax(nowmax,max1[u].fi+max2[u].fi)) optx=max1[u].se,opty=max2[u].se;
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	int rt=1;
	while(1){
		nowmax=-1;
		f[rt]=-1,dep[rt]=1;
		dfs(rt,-1);
		if(nowmax==0) return printf("! %d\n",rt),0;
		int tmp=ask(optx,opty);
		while(optx!=opty){
			if(dep[optx]<dep[opty]) swap(optx,opty);
			vis[optx]=1;
			optx=f[optx];
		}
		vis[optx]=1;
		vis[tmp]=0;
		rt=tmp;
	}
	return 0;
}