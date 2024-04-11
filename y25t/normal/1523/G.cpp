#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 50005
#define M 100005

int n,m;
pii a[M];

std::vector<int> vec[N];

#define mn(p) (p?p->mn:inf)
struct node{
	int mn;
	node *son[2];
	node(){
		mn=inf;
		son[0]=son[1]=0;
	}
};
inline void Ins(node *&p,int L,int R,int x,int d){
	if(!p)
		p=new node();
	if(L==R){
		p->mn=std::min(p->mn,d);
		return;
	}
	int mid=(L+R)>>1;
	if(x<=mid)
		Ins(p->son[0],L,mid,x,d);
	else
		Ins(p->son[1],mid+1,R,x,d);
	p->mn=std::min(mn(p->son[0]),mn(p->son[1]));
}
inline int Qry(node *p,int L,int R,int l,int r){
	if(L>r||R<l||!p)
		return inf;
	if(l<=L&&R<=r)
		return p->mn;
	int mid=(L+R)>>1;
	return std::min(Qry(p->son[0],L,mid,l,r),Qry(p->son[1],mid+1,R,l,r));
}

node *rt[N];
inline int lb(int x){
	return x&-x;
}
inline void ins(int L,int R,int d){
	for(;R<=n;R+=lb(R))
		Ins(rt[R],1,n,L,d);
}
inline int qry(int L,int R){
	int res=inf;
	for(;R;R-=lb(R))
		res=std::min(res,Qry(rt[R],1,n,L,n));
	return res;
}

inline ll sol(int L,int R,int x){
	if(R-L+1<x)
		return 0;
	int p=qry(L,R);
	if(p==inf)
		return 0;
	return a[p].sec-a[p].fir+1+sol(L,a[p].fir-1,x)+sol(a[p].sec+1,R,x);
}

ll ans[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].fir,&a[i].sec);
		vec[a[i].sec-a[i].fir+1].push_back(i);
	}
	for(int x=n;x;x--){
		for(auto i:vec[x])
			ins(a[i].fir,a[i].sec,i);
		ans[x]=sol(1,n,x);
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
}