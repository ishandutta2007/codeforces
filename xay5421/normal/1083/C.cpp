#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,K=20;
int n,Q,p[N],q[N],fa[N],tin[N],tou[N],ind,lg[N*2],f[N*2][K];
vector<int>e[N];
int min_(int x,int y){return tin[x]<tin[y]?x:y;}
void dfs1(int k1){
	f[++ind][0]=k1,tin[k1]=ind;
	each(x,e[k1]){
		dfs1(x);
		f[++ind][0]=k1;
	}
	tou[k1]=ind;
}
int LCA(int u,int v){
	int l=tin[u],r=tin[v];
	if(l>r)swap(l,r);
	int x=lg[r-l+1];
	return min_(f[l][x],f[r-(1<<x)+1][x]);
}
inline bool inSub(int u,int v){ // u in sub(v)
	return tin[v]<=tin[u]&&tin[u]<=tou[v];
}
inline bool inPath(int u,int v,int w){ // u in path(v,w)
	int t=LCA(v,w);
	return inSub(u,t)&&(inSub(v,u)||inSub(w,u));
}
struct node{
	int u,v;
	node():u(-1),v(-1){}
	node(int x):u(x),v(x){}
	node(int x,int y):u(x),v(y){}
	node operator+(const node&rhs)const{
		if(u==-1||rhs.u==-1)return node();
		// u->(v,rhs.v)->rhs.u
#define F(a,b,c,d) if(inPath(b,a,d)&&inPath(c,a,d))return node(a,d)
		//if(inPath(v,u,rhs.u)&&inPath(rhs.v,u,rhs.u))return node(u,rhs.u);
		F(u,rhs.u,rhs.v,v);
		F(rhs.u,u,v,rhs.v);
		F(u,rhs.v,v,rhs.u);
		F(v,rhs.v,u,rhs.u);
		F(u,rhs.u,v,rhs.v);
		F(v,rhs.u,u,rhs.v);
		return node();
#undef F
	}
}tr[N*4];
void upd(int k1){
	tr[k1]=tr[k1*2]+tr[k1*2+1];
}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		tr[k1]=node(q[k2]);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void fix(int k1,int k2,int k3,int k4){
	if(k2==k3){
		tr[k1]=node(q[k2]);
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)fix(k1*2,k2,mid,k4);else fix(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
bool gg;
int ans;
node res;
void query(int k1,int k2,int k3){
	node cur=res.u?res+tr[k1]:tr[k1];
	if(cur.u!=-1){
		ans=k3;
		res=cur;
		return;
	}
	if(k2==k3){
		gg=1;
		return;
	}
	int mid=(k2+k3)>>1;
	query(k1*2,k2,mid);
	if(gg)return;
	query(k1*2+1,mid+1,k3);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N*2-1)lg[i]=lg[i>>1]+1;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&p[i]);
		++p[i];
		q[p[i]]=i;
	}
	rep(i,2,n){
		scanf("%d",&fa[i]);
		e[fa[i]].pb(i);
	}
	dfs1(1);
	rep(j,1,K-1)rep(i,1,ind-(1<<j)+1){
		f[i][j]=min_(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	bud(1,1,n);
	scanf("%d",&Q);
	rep(_,1,Q){
		//D("_=%d\n",_);
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int i,j;
			scanf("%d%d",&i,&j);
			swap(p[i],p[j]);
			swap(q[p[i]],q[p[j]]);
			fix(1,1,n,p[i]),fix(1,1,n,p[j]);
			//bud(1,1,n);
		}else{
			ans=1;
			gg=0;
			res=node(0);
			query(1,1,n);
			printf("%d\n",ans);
		}
	}
	return 0;
}