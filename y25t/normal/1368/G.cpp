#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define N 200005

int n,m;
char s[N],a[N];

inline int num(int x,int y){
	return (x-1)*m+y;
}

int deg[N];
int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
	deg[v]++;
}

int dfn[N],_dfn,mx[N];
inline void dfs(int u){
	mx[u]=dfn[u]=++_dfn;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs(v);
		mx[u]=std::max(mx[u],mx[v]);
	}
}

struct qry{
	int l,r,d;
};
std::vector<qry> q[N];

struct node{
	int sum,mn;
}t[N<<2];
inline void upd(int p,int L,int R){
	if(t[p].mn)
		t[p].sum=R-L+1;
	else if(L!=R)
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	else
		t[p].sum=0;
}
inline void add(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		t[p].mn+=d;
		upd(p,L,R);
		return;
	}
	int mid=(L+R)>>1;
	add(p<<1,L,mid,l,r,d);
	add(p<<1|1,mid+1,R,l,r,d);
	upd(p,L,R);
}

ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='U'&&i+2<=n)
				addedge(num(i+2,j),num(i,j));
			if(s[j]=='D'&&i-2>=1)
				addedge(num(i-2,j),num(i,j));
			if(s[j]=='L'&&j+2<=m)
				addedge(num(i,j+2),num(i,j));
			if(s[j]=='R'&&j-2>=1)
				addedge(num(i,j-2),num(i,j));
			a[num(i,j)]=s[j];
		}
	}
	for(int i=1;i<=n*m;i++)
		if(!deg[i])
			dfs(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			printf("%d ",dfn[num(i,j)]);
//		puts("");
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i%2==j%2){
				if(a[num(i,j)]=='U'){
					q[dfn[num(i,j)]].push_back((qry){dfn[num(i+1,j)],mx[num(i+1,j)],1});
					q[mx[num(i,j)]+1].push_back((qry){dfn[num(i+1,j)],mx[num(i+1,j)],-1});
				}
				if(a[num(i,j)]=='D'){
					q[dfn[num(i,j)]].push_back((qry){dfn[num(i-1,j)],mx[num(i-1,j)],1});
					q[mx[num(i,j)]+1].push_back((qry){dfn[num(i-1,j)],mx[num(i-1,j)],-1});
				}
				if(a[num(i,j)]=='L'){
					q[dfn[num(i,j)]].push_back((qry){dfn[num(i,j+1)],mx[num(i,j+1)],1});
					q[mx[num(i,j)]+1].push_back((qry){dfn[num(i,j+1)],mx[num(i,j+1)],-1});
				}
				if(a[num(i,j)]=='R'){
					q[dfn[num(i,j)]].push_back((qry){dfn[num(i,j-1)],mx[num(i,j-1)],1});
					q[mx[num(i,j)]+1].push_back((qry){dfn[num(i,j-1)],mx[num(i,j-1)],-1});
				}
			}
	for(int i=1;i<=n*m;i++){
		for(std::vector<qry>::iterator it=q[i].begin();it!=q[i].end();it++){
			add(1,1,n*m,it->l,it->r,it->d);
//			printf("^%d %d %d %d\n",i,it->l,it->r,it->d);
		}
//		printf("&%d\n",t[1].sum);
		ans+=t[1].sum;
	}
	printf("%lld\n",ans);
}