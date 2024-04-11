#include <cstdio>
#include <algorithm>
#define max_n 300000
using namespace std;
typedef const int& ci;
int tree[max_n-1<<2];
int a[max_n+2];
void build(ci rt,ci l,ci r){
	if(l==r){
		tree[rt]=a[l];
		return;
	}
	int mid=l+r>>1,lsn=rt<<1,rsn=lsn|1;
	build(lsn,l,mid);
	build(rsn,mid+1,r);
	tree[rt]=max(tree[lsn],tree[rsn]);
}
template<typename T>void maxify(T&x,const T&y){
	y>x&&(x=y);
}
int query(ci rt,ci l,ci r,ci left,ci right){
	if(left<=l&&right>=r)
		return tree[rt];
	int mid=l+r>>1,lsn=rt<<1,rsn=lsn|1,ret=0;
	left<=mid&&(maxify(ret,query(lsn,l,mid,left,right)),1);
	right>mid&&(maxify(ret,query(rsn,mid+1,r,left,right)),1);
	return ret;
}
int nxt[max_n+2],pos[max_n+2];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0; ++i<=n; scanf("%d",a+i),pos[i]=n+1);
	build(1,1,n),nxt[n+1]=n+1;
	for(int i=n+1; --i; pos[a[i]]=i){
		nxt[i]=min(pos[a[i]],nxt[i+1]);
		for(int j=i-1,x; ++j<nxt[i]; i+(x=query(1,1,n,i,j))-1>j?(j=i+x-2):(++ans));
	}
	printf("%d\n",ans);
	return 0;
}