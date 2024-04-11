#include<stdio.h>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=200005,maxt=maxn<<2;
int n;
int a[maxn],ans[maxn];
vector<int>v[maxn];
struct node{
	int lmx,rmx,sum;
}ept;
node merge(node a,node b){
	return node{max(a.lmx,a.sum+b.lmx),max(b.rmx,b.sum+a.rmx),a.sum+b.sum};
}
struct segmenttree{
	int rec;
	node t[maxt];
	inline void pushup(int now){
		t[now]=merge(t[lc(now)],t[rc(now)]);
	}
	void build(int l,int r,int now){
		if(l==r){
			t[now].lmx=t[now].rmx=t[now].sum=-1;
			return ;
		}
		build(l,mid,lc(now)),build(mid+1,r,rc(now)),pushup(now);
	}
	void modify(int l,int r,int now,int p,int v){
		if(l==r){
			t[now].lmx=t[now].rmx=t[now].sum=v;
			return ;
		}
		if(p<=mid)
			modify(l,mid,lc(now),p,v);
		else modify(mid+1,r,rc(now),p,v);
		pushup(now);
	}
	node query(int l,int r,int now,int L,int R){
		if(L>R)
			return ept;
		if(L<=l&&r<=R)
			return t[now];
		if(L<=mid&&mid<R)
			return merge(query(l,mid,lc(now),L,R),query(mid+1,r,rc(now),L,R));
		if(L<=mid)
			return query(l,mid,lc(now),L,R);
		return query(mid+1,r,rc(now),L,R);
	}
}p;
int main(){
	ept=node{0,0,0};
	scanf("%d",&n),p.build(1,n,1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[a[i]].push_back(i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			p.modify(1,n,1,k,1);
		}
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ans[k]=p.query(1,n,1,1,k).rmx+p.query(1,n,1,k,n).lmx-2;
		}
	}
	p.build(1,n,1);
	for(int i=n;i>=1;i--){
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			p.modify(1,n,1,n-k+1,1);
		}
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ans[k]=max(ans[k],p.query(1,n,1,1,n-k+1).rmx+p.query(1,n,1,n-k+1,n).lmx-1);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]/2,i==n? '\n':' ');
	return 0;
}