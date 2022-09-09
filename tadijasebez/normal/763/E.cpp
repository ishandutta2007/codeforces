#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=600050;
int fa[N],go[N][2],mn[N],val[N],tag[N];
void upd(int x){if(x)swap(go[x][0],go[x][1]),tag[x]^=1;}
void push(int x){if(tag[x])upd(go[x][0]),upd(go[x][1]),tag[x]=0;}
void pull(int x){mn[x]=min({mn[go[x][0]],val[x],mn[go[x][1]]});}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[y][p]=w;go[x][p^1]=y;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
int Find(int x){push(x);return val[x]==mn[x]?x:mn[go[x][0]]==mn[x]?Find(go[x][0]):Find(go[x][1]);}
void cl(int x){if(~pd(x))cl(fa[x]);push(x);}
void splay(int x){for(cl(x);~pd(x);rot(x))if(~pd(fa[x]))rot(pd(fa[x])==pd(x)?fa[x]:x);}
void access(int x){for(splay(x),go[x][1]=0,pull(x);fa[x];rot(x))splay(fa[x]),go[fa[x]][1]=x,pull(fa[x]);}
void make_rt(int x){access(x);upd(x);}
void path(int x,int y){make_rt(x);access(y);}
void link(int x,int y){make_rt(y);fa[y]=x;}
void cut(int x,int y){path(x,y);go[y][0]=0;fa[x]=0;pull(y);}
int path_mn(int x,int y){path(x,y);int m=Find(y);splay(m);return m;}
bool same(int x,int y){path(x,y);return fa[x]!=0;}
const int M=100050;
int sum[M],ans[M];
void Set(int i,int f){for(;i;i-=i&-i)sum[i]+=f;}
int Get(int i){int ans=0;for(;i<M;i+=i&-i)ans+=sum[i];return ans;}
vector<int> E[M];
vector<pair<int,int>> Qs[M];
int main(){
	mn[0]=val[0]=1e9;
	int n,k,m,tsz;
	scanf("%i %i %i",&n,&k,&m);tsz=n;for(int i=1;i<=n;i++)val[i]=mn[i]=1e9;
	for(int i=1,u,v;i<=m;i++)scanf("%i %i",&u,&v),E[max(u,v)].pb(min(u,v));
    int q;
    scanf("%i",&q);
    for(int i=1,l,r;i<=q;i++)scanf("%i %i",&l,&r),Qs[r].pb({l,i});
    for(int i=1;i<=n;i++){
		for(int j:E[i]){
			if(!same(j,i)){
				tsz++;val[tsz]=mn[tsz]=j;
				link(i,tsz);
				link(j,tsz);
				Set(j,1);
			}else{
				int m=path_mn(j,i);
				if(val[m]<j){
					Set(val[m],-1);
					fa[go[m][0]]=fa[go[m][1]]=0;
					go[m][0]=go[m][1]=0;
					tsz++;val[tsz]=mn[tsz]=j;
					link(i,tsz);
					link(j,tsz);
					Set(j,1);
				}
			}
		}
		for(auto Q:Qs[i])ans[Q.second]=(i-Q.first+1)-Get(Q.first);
    }
    for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}