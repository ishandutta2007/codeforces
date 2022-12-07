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
const int N=200005;
const int M=19*2*2*N;
pii e[M];
struct fucker{
	int x,y,id;
}q[2][N];
int n,T,vq[N],nq[N],fa[2][N];
int dfn[2][N],ed[2][N],id[N];
vector<int> E[2][N];
int head1[2][N*4],head2[2][N*4];
int vis[2][N],tot;
void dfs(int x){
	dfn[T][x]=++dfn[T][0];
	for (auto i:E[T][x]) dfs(i);
	ed[T][x]=dfn[T][0];
}
bool cmp1(int x,int y){
	return dfn[T][q[T][x].y]<dfn[T][q[T][y].y];
}
bool cmp2(int x,int y){
	return dfn[T][q[T][x].x]>dfn[T][q[T][y].x];
}
void insert1(int k,int l,int r,int id){
	e[++tot]=pii(q[T][id].id,head1[T][k]);
	head1[T][k]=tot;
	if (l==r) return;
	int mid=(l+r)/2;
	if (dfn[T][q[T][id].x]<=mid)
		insert1(k*2,l,mid,id);
	else insert1(k*2+1,mid+1,r,id);
}
void insert2(int k,int l,int r,int id){
	e[++tot]=pii(q[T][id].id,head2[T][k]);
	head2[T][k]=tot;
	if (l==r) return;
	int mid=(l+r)/2;
	if (dfn[T][q[T][id].y]<=mid)
		insert2(k*2,l,mid,id);
	else insert2(k*2+1,mid+1,r,id);
}
void find(int k,int l,int r,int x){
	if (dfn[T][x]<=l&&r<=ed[T][x]){
		int y;
		for (;head1[T][k]&&dfn[T][q[T][e[head1[T][k]].fi].y]> ed[T][x];head1[T][k]=e[head1[T][k]].se)
			if (!vis[!T][y=e[head1[T][k]].fi]) nq[++*nq]=y,vis[!T][y]=1;
		for (;head2[T][k]&&dfn[T][q[T][e[head2[T][k]].fi].x]<dfn[T][x];head2[T][k]=e[head2[T][k]].se)
			if (!vis[!T][y=e[head2[T][k]].fi]) nq[++*nq]=y,vis[!T][y]=1;
		return;
	}
	int mid=(l+r)/2;
	if (dfn[T][x]<=mid) find(k*2,l,mid,x);
	if (ed[T][x]>mid) find(k*2+1,mid+1,r,x);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (T=0;T<=1;++T){
		For(i,2,n){
			scanf("%d",&fa[T][i]);
			E[T][fa[T][i]].PB(i);
		}
		dfs(1);
	}
	for (T=0;T<=1;++T){
		For(i,2,n) q[T][i]=(fucker){i,fa[!T][i],i};
		For(i,2,n)
			if (dfn[T][q[T][i].x]>dfn[T][q[T][i].y])
				swap(q[T][i].x,q[T][i].y);
		For(i,2,n) id[i]=i;
		sort(id+2,id+n+1,cmp1);
		For(i,2,n) insert1(1,1,n,id[i]);
		sort(id+2,id+n+1,cmp2);
		For(i,2,n) insert2(1,1,n,id[i]);
	}
	scanf("%d",&vq[1]);
	vq[0]=1; ++vq[1];
	vis[0][vq[1]]=1;
	for (T=0;*vq;T^=1){
		puts(T?"Red":"Blue");
		sort(vq+1,vq+*vq+1);
		For(i,1,*vq){
			printf("%d ",vq[i]-1);
			find(1,1,n,vq[i]);
		}
		puts("");
		if (!*nq) return 0;
		memcpy(vq,nq,nq[0]*4+4);
		memset(nq,0,nq[0]*4+4);
	}
}