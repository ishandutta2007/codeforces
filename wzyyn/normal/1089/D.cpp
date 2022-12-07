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
const int M=165;
const int N=100005;
vector<int> e[N];
int n,m,rt,sz[N],dep[N],fa[N];
int del[N],vis[N],spe[N],id[N];
int q[M],fap[M],d[M][N];
int dfn[N],ed[N],S[N];
vector<ll> v1[M],v2[M];
ll ans;
void topo(){
	static int q[N],deg[N];
	int h=0,t=0;
	For(i,1,n) deg[i]=e[i].size(),sz[i]=1;
	For(i,1,n) if (deg[i]==1) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		del[x]=1;
		ans+=1ll*(n-sz[x])*sz[x];
		for (auto i:e[x]) if (!del[i]){
			sz[i]+=sz[x];
			if (--deg[i]==1) q[++t]=i;
		}
	}
}
void dfs(int x){
	vis[x]=1;
	dfn[x]=++*dfn;
	int sum=0;
	for (auto i:e[x])
		if (!del[i]&&i!=fa[x]){
			if (!vis[i]){
				fa[i]=x;
				dep[i]=dep[x]+1;
				dfs(i); sum+=(S[i]!=0);
			}
			else if (dep[i]<dep[x])
				q[++*q]=x,q[++*q]=i,S[x]=S[i]=1;
		}
	//cout<<x<<' '<<sum<<' '<<S[x]<<endl;
	if (S[x]==0&&sum>=2) q[++*q]=x;
	S[x]|=(sum!=0);
	ed[x]=*dfn;
}
void initD(int S,int *d){
	static int q[N];
	For(i,1,n) d[i]=-1;
	int h=0,t=1;
	q[1]=S; d[S]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (d[i]==-1){
				d[i]=d[x]+1;
				q[++t]=i;
			}
	}
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
} 
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	topo();
	for (rt=1;del[rt];++rt);
	if (rt>n) return printf("%lld\n",ans),0; 
	dfs(rt); q[++*q]=rt;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,*q) initD(q[i],d[i]);
	For(i,1,*q) spe[q[i]]=1;
	ans*=2;
	//For(i,1,*q) cout<<q[i]<<' '; cout<<endl;
	//For(i,1,n) cout<<sz[i]<<' '; cout<<endl;
	//For(i,1,n) cout<<del[i]<<' '; cout<<endl;
	For(i,1,*q) if (q[i]!=rt){
		int j=fa[q[i]],top=0;
		for (;!spe[j];id[++top]=sz[j],j=fa[j]);
		fap[i]=lower_bound(q+1,q+*q+1,j)-q;
		id[top+1]=0;
		v1[i].resize(top+2);
		v2[i].resize(top+2);
		For(j,1,top+1) v1[i][j]=v1[i][j-1]+id[j];
		For(j,1,top+1) v2[i][j]=v2[i][j-1]+1ll*j*id[j];
		int len=d[i][q[fap[i]]];
		For(j,1,top){
			int d=(len+top+1)/2;
			int pr=min(top,j+d);
			ll tmp=(v2[i][pr]-v2[i][j])-1ll*(v1[i][pr]-v1[i][j])*j;
			tmp+=(v1[i][top+1]-v1[i][pr])*(top+1+len+j);
			tmp-=(v2[i][top+1]-v2[i][pr]);
			ans+=2ll*tmp*id[j];
		}
	}
	For(i,1,*q) For(j,1,n)
		if (!del[j]) ans+=1ll*d[i][j]*sz[q[i]]*sz[j];
	For(i,1,n) if (!del[i]&&!spe[i]){
		For(j,1,*q) ans+=1ll*d[j][i]*sz[q[j]]*sz[i];
		For(j,1,*q) if (q[j]!=rt){
			if (isfa(q[fap[j]],i)&&isfa(i,q[j])) continue;
			int d1=d[j][i],d2=d[fap[j]][i];
			int len=dep[q[j]]-dep[q[fap[j]]];
			if (len==1) continue;
			int l1=(d2+len-d1)/2;
			l1=min(l1,len-1);
			int l2=len-l1-1;
			//cout<<"AXIB "<<i<<' '<<q[j]<<' '<<q[fap[j]]<<' '<<l1<<' '<<l2<<' '<<d1<<' '<<d2<<endl;
			ll v=1ll*d1*v1[j][l1]+v2[j][l1];
			v+=1ll*d2*(v1[j].back()-v1[j][l1]);
			v+=1ll*(v1[j].back()-v1[j][l1])*(v1[j].size()-1);
			v-=1ll*(v2[j].back()-v2[j][l1]);
			ans+=sz[i]*v;
		}
	}
	printf("%lld\n",ans/2);
}
/*
4 4
1 2
2 3
3 1
1 4
*/