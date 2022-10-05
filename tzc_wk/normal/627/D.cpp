#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=2e5+5;
int n,k,a[MAXN];
struct graph{
	int ecnt,head[MAXN],nxt[MAXN<<1],to[MAXN<<1];
	void clear(){ecnt=0;fill0(head);fill0(nxt);fill0(to);}
	graph(){clear();}
	void adde(int u,int v){
		to[++ecnt]=v;nxt[ecnt]=head[u];head[u]=ecnt;
	}
} t;
int siz[MAXN];
void dfspre(int x,int f){
	siz[x]=1;
	for(int e=t.head[x];e;e=t.nxt[e]){
		int y=t.to[e];if(y==f) continue;
		dfspre(y,x);siz[x]+=siz[y];
	}
}
bool mark[MAXN];
int hav[MAXN],dp[MAXN],ff[MAXN],out[MAXN],maxdp[MAXN];
void dfs(int x,int f){
	int mx=0;
	for(int e=t.head[x];e;e=t.nxt[e]){
		int y=t.to[e];if(y==f) continue;
		dfs(y,x);hav[x]+=hav[y];
		if(hav[y]==siz[y]) dp[x]+=siz[y];
		else mx=max(mx,dp[y]);
	}
	dp[x]+=mx;
	if(!mark[x]) dp[x]=0;
	else dp[x]++;
}
void cgrt(int x,int f){
	int mx=0,sum=0;
	for(int e=t.head[x];e;e=t.nxt[e]){
		int y=t.to[e];
		if(y!=f){
			if(hav[y]==siz[y]) ff[x]+=siz[y];
			else mx=max(mx,dp[y]);
		} else {
			if(hav[1]-hav[x]==siz[1]-siz[x]) ff[x]+=siz[1]-siz[x];
			else mx=max(mx,out[x]);
		}
	}
	ff[x]+=mx;
	if(!mark[x]) ff[x]=0;
	else ff[x]++;
	vector<int> son;
	for(int e=t.head[x];e;e=t.nxt[e]) son.push_back(t.to[e]);
	mx=sum=0;
	for(int i=0;i<son.size();i++){
		int y=son[i];
		if(y!=f){
			maxdp[y]=max(maxdp[y],mx);
			out[y]+=sum;
			if(hav[y]==siz[y]) sum+=hav[y];
			else mx=max(mx,dp[y]);
		} else {
			if(hav[1]-hav[x]==siz[1]-siz[x]) sum+=siz[1]-siz[x];
			else mx=max(mx,out[x]);
		}
	}
	mx=sum=0;
	for(int i=son.size()-1;~i;i--){
		int y=son[i];
		if(y!=f){
			maxdp[y]=max(maxdp[y],mx);
			out[y]+=sum;
			if(hav[y]==siz[y]) sum+=hav[y];
			else mx=max(mx,dp[y]);
		} else {
			if(hav[1]-hav[x]==siz[1]-siz[x]) sum+=siz[1]-siz[x];
			else mx=max(mx,out[x]);
		}
	}
	for(int e=t.head[x];e;e=t.nxt[e]){
		int y=t.to[e];if(y==f) continue;
		out[y]+=maxdp[y];
		if(!mark[x]) out[y]=0;
		else out[y]++;
		cgrt(y,x);
	}
}
bool check(int mid){
	memset(mark,0,sizeof(mark));
	memset(hav,0,sizeof(hav));
	memset(dp,0,sizeof(dp));
	memset(ff,0,sizeof(ff));
	memset(out,0,sizeof(out));
	memset(maxdp,0,sizeof(maxdp));
	for(int i=1;i<=n;i++) if(a[i]>=mid) mark[i]=hav[i]=1;
	dfs(1,0);cgrt(1,0);
//	for(int i=1;i<=n;i++) printf("%d\n",dp[i]);
//	for(int i=1;i<=n;i++) printf("%d\n",ff[i]);
	for(int i=1;i<=n;i++) if(ff[i]>=k) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		t.adde(u,v);t.adde(v,u);
	} dfspre(1,0);
	int l=1,r=1e6,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	} printf("%d\n",ans);
	return 0;
}