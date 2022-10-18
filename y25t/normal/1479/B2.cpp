#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 100005

int n,a[N];

struct node{
	int mn,add;
	
	node(){
		mn=inf;
		add=0;
	}
}t[N<<2];
inline void pshd(int p){
	t[p<<1].mn+=t[p].add;
	t[p<<1].add+=t[p].add;
	t[p<<1|1].mn+=t[p].add;
	t[p<<1|1].add+=t[p].add;
	t[p].add=0;
}
inline void add(){
	t[1].mn++;
	t[1].add++;
}
inline int mn(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return inf;
	if(l<=L&&R<=r)
		return t[p].mn;
	pshd(p);
	int mid=(L+R)>>1;
	return std::min(mn(p<<1,L,mid,l,r),mn(p<<1|1,mid+1,R,l,r));
}
inline void chg(int p,int L,int R,int x,int d){
//	if(!x)
//		return;
	if(L==R){
		t[p].mn=std::min(t[p].mn,d);
		return;
	}
	pshd(p);
	int mid=(L+R)>>1;
	if(x<=mid)
		chg(p<<1,L,mid,x,d);
	else
		chg(p<<1|1,mid+1,R,x,d);
	t[p].mn=std::min(t[p<<1].mn,t[p<<1|1].mn);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	chg(1,0,n,0,0);
	for(int i=1;i<=n;i++){
		int tmp=std::min(mn(1,0,n,0,a[i]-1),mn(1,0,n,a[i]+1,n));
		tmp=std::min(tmp+1,mn(1,0,n,a[i],a[i]));
		if(a[i]!=a[i-1])
			add();
		chg(1,0,n,a[i-1],tmp);
//		printf("^%d %d %d\n",i,a[i-1],tmp);
//		for(int j=0;j<=n;j++)
//			printf("%d ",mn(1,0,n,j,j));
//		puts("");
	}
	printf("%d\n",mn(1,0,n,0,n));
}