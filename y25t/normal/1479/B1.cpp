#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 100005

int n,a[N];

struct node{
	int mx,add;
	
	node(){
//		mx=inf;
		add=0;
	}
}t[N<<2];
inline void pshd(int p){
	t[p<<1].mx+=t[p].add;
	t[p<<1].add+=t[p].add;
	t[p<<1|1].mx+=t[p].add;
	t[p<<1|1].add+=t[p].add;
	t[p].add=0;
}
inline void add(){
	t[1].mx++;
	t[1].add++;
}
inline int mx(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return -inf;
	if(l<=L&&R<=r)
		return t[p].mx;
	pshd(p);
	int mid=(L+R)>>1;
	return std::max(mx(p<<1,L,mid,l,r),mx(p<<1|1,mid+1,R,l,r));
}
inline void chg(int p,int L,int R,int x,int d){
	if(L==R){
		t[p].mx=std::max(t[p].mx,d);
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	if(x<=mid)
		chg(p<<1,L,mid,x,d);
	else
		chg(p<<1|1,mid+1,R,x,d);
	t[p].mx=std::max(t[p<<1].mx,t[p<<1|1].mx);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tmp=std::max(mx(1,1,n,1,a[i]-1),mx(1,1,n,a[i]+1,n));
		if(a[i]!=a[i-1])
			add();
		chg(1,1,n,a[i-1],tmp+1);
//		printf("^%d\n",i);
//		for(int j=1;j<=n;j++)
//			printf("%d ",mx(1,1,n,j,j));
//		puts("");
	}
	printf("%d\n",mx(1,1,n,1,n));
}