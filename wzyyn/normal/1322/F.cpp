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
const int N=500005;
int n,m;
vector<int> e[N];
namespace DSU{
	int fa[N],v[N];
	int get(int x){
		if (x==fa[x]) return x;
		int f=fa[x];
		fa[x]=get(fa[x]);
		v[x]^=v[f];
		return fa[x];
	}
	void build(){
		For(i,1,n) fa[i]=i,v[i]=0;
	}
	void merge(int x,int y,int vv){
		int px=get(x),py=get(y);
		if (px==py){
			if (v[x]^v[y]^vv){
				puts("-1");
				exit(0);
			}
		}
		else{
			fa[px]=py;
			v[px]=v[x]^v[y]^vv;
		}
	}
}
namespace TR{
	int S[N],SS[N];
	int fa[N],sz[N],dep[N];
	int pos[N],dfn[N],top[N];
	void dfs1(int x){
		sz[x]=1;
		for (auto i:e[x])
			if (i!=fa[x]){
				fa[i]=x;
				dep[i]=dep[x]+1;
				dfs1(i);
				sz[x]+=sz[i];
			}
	}
	void dfs2(int x,int tp){
		dfn[x]=++*dfn;
		pos[*dfn]=x;
		top[x]=tp;
		int k=0;
		for (auto i:e[x])
			if (i!=fa[x]&&sz[i]>sz[k])
				k=i;
		if (k) dfs2(k,tp);
		for (auto i:e[x])
			if (i!=fa[x]&&i!=k)
				dfs2(i,i);
	}
	int LCA(int x,int y){
		for (;top[x]!=top[y];x=fa[top[x]])
			if (dep[top[x]]<dep[top[y]])
				swap(x,y);
		return dep[x]<dep[y]?x:y;
	}
	int jmp(int x,int y){
		for (;;){
			if (dep[top[x]]<=dep[y])
				return pos[dfn[y]+1];
			if (dep[top[x]]==dep[y]+1)
				return top[x];
			x=fa[top[x]];
		}
	}
	void build(){
		dfs1(1);
		dfs2(1,1);
	}
	void build2(){
		Rep(i,n,1){
			int x=pos[i];
			S[fa[x]]+=S[x];
			SS[fa[x]]+=SS[x];
			if (SS[x])
				DSU::merge(x,fa[x],0);
		}
	}
	void insert_que(int x,int y){
		int L=LCA(x,y);
		S[x]++; S[y]++; S[L]-=2;
		if (dep[x]^dep[L]) SS[x]++,SS[x=jmp(x,L)]--;
		if (dep[y]^dep[L]) SS[y]++,SS[y=jmp(y,L)]--;
		if ((x^L)&&(y^L)) DSU::merge(x,y,1);
	}
}
int v0[N],v1[N];
int vis[N],f[N],T;
int cc[N],fl[N];
bool check(int K){
	static int q[N];
	Rep(i,n,1){
		int x=TR::pos[i],y=TR::fa[x];
		int vl=0,vr=0;
		++T; *q=0;
		for (auto j:e[x])
			if (j!=y&&TR::S[j]){
				int c=DSU::fa[j];
				if (vis[c]!=T) vis[c]=T,q[++*q]=c,v0[c]=v1[c]=0;
				if (DSU::v[j]==0) v0[c]=max(v0[c],f[j]);
				else v1[c]=max(v1[c],f[j]);
			}
		if (vis[DSU::fa[x]]==T){
			int c=DSU::fa[x];
			vl=v0[c]; vr=v1[c];
			if (DSU::v[x]) swap(vl,vr);
		}
		int vmn=0,vmx=0;
		For(j,1,*q)
			if (q[j]!=DSU::fa[x]){
				if (v0[q[j]]>v1[q[j]])
					swap(v0[q[j]],v1[q[j]]);
				vmn=max(vmn,v0[q[j]]);
				vmx=max(vmx,v1[q[j]]);
			}
		if (max(vmn,min(vl,vr))+max(vmx,max(vl,vr))>=K) return 0;
		f[x]=(max(vmn,vl)+max(vmx,vr)>=K?max(vmx,vl):max(vmn,vl))+1;
	}
	return 1;
}
void construct(int K){
	static int q[N];
	For(i,1,n){
		int x=TR::pos[i],y=TR::fa[x];
		++T; *q=0;
		for (auto j:e[x])
			if (j!=y&&TR::S[j]){
				int c=DSU::fa[j];
				if (vis[c]!=T) vis[c]=T,q[++*q]=c,v0[c]=v1[c]=0;
				if (DSU::v[j]==0) v0[c]=max(v0[c],f[j]);
				else v1[c]=max(v1[c],f[j]);
			}
		For(j,1,*q){
			cc[q[j]]=fl[x];
			if (q[j]!=DSU::fa[x])
				cc[q[j]]^=(v0[q[j]]>f[x]-1||v1[q[j]]+f[x]>K);
			else cc[q[j]]^=DSU::v[x];
		}
		for (auto j:e[x])
			if (j!=y&&TR::S[j])
				fl[j]=cc[DSU::fa[j]]^DSU::v[j];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	TR::build();
	DSU::build();
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		TR::insert_que(x,y);
	}
	TR::build2();
	For(i,1,n) DSU::get(i);
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	check(ans);
	construct(ans);
	For(i,1,n) printf("%d ",!fl[i]?f[i]:ans+1-f[i]);
}