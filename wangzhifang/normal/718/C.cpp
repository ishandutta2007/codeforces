#include <cstdio>
#include <cstring>
#define siz 2
#define max_n 100000
#define max_nod max_n<<2
#define mod 1000000007
using namespace std;
template<typename T>void mpls(T&x,const T&y){
	(x+=y)>=mod&&(x-=mod);
}
template<typename T>T m(T x){
	return x>=mod?x-mod:x;
}
template<typename T1,typename T2>T1 quickpow(T1 a,T2 k){
	T1 ret=1;
	for(; k; a*=a,k>>=1)
		(k&1)&&(ret*=a,1);
	return ret;
}
struct square{
	long long a[3][3];
	square(){}
	square(long long k){
		memset(a,0,sizeof(a));
		for(int i=0; ++i<=siz; a[i][i]=k);
	}
	square(long long a,long long b,long long c,long long d):a{{},{0,a,b},{0,c,d}}{}
	const long long*operator[](int k)const{
		return a[k];
	}
	long long*operator[](int k){
		return a[k];
	}
	friend square operator+(square x,const square&y){
		for(int i=0; ++i<=siz; )
			for(int j=0; ++j<=siz; mpls(x[i][j],y[i][j]));
		return x;
	}
	friend square operator*(const square&x,const square&y){
		square z=0;
		for(int i=0; ++i<=siz; )
			for(int j=0; ++j<=siz; )
				for(int k=0; ++k<=siz; z[i][j]=(z[i][j]+x[i][k]*y[k][j])%mod);
		return z;
	}
	square&operator*=(const square&y){//left times
		return *this=y**this;
	}
};
typedef square sq;
typedef const int& ci;
sq u(1,1,1,0);
int a[max_n+1];
sq sum[max_nod],tag[max_nod];
bool tgd[max_nod];
int lrt[max_nod],rlt[max_nod],lsn[max_nod],rsn[max_nod];
#define ptg(now,tg) sum[now]*=tg,tag[now]*=tg,tgd[now]=1
void pushdown(ci now){
	int ltr=lsn[now],rtr=rsn[now];
	sq tg=tag[now];
	ptg(ltr,tg),ptg(rtr,tg);
	tag[now]=1,tgd[now]=0;
}
void build(ci now,ci lft,ci rit){
	if(lft==rit){
		sum[now]=quickpow(u,a[lft]),tag[now]=1,tgd[now]=0;
		return;
	}
	int&lrt_=lrt[now],&lsn_=lsn[now],&rlt_=rlt[now],&rsn_=rsn[now];
	lrt_=lft+rit>>1,lsn_=now<<1;
	rlt_=lrt_+1,rsn_=lsn_|1;
	build(lsn_,lft,lrt_),build(rsn_,rlt_,rit);
	sum[now]=sum[lsn_]+sum[rsn_],tag[now]=1,tgd[now]=0;
}
int query(ci now,ci lft,ci rit,ci l,ci r){
//	printf("query %d %d %d\n",now,lft,rit);
	if(lft>r||rit<l)
		return 0;
	if(l<=lft&&rit<=r)
		return sum[now][1][2];
	tgd[now]&&(pushdown(now),1);
	return m(query(lsn[now],lft,lrt[now],l,r)+query(rsn[now],rlt[now],rit,l,r));
}
void modify(ci now,ci lft,ci rit,ci l,ci r,const sq&frc){
	if(lft>r||rit<l)
		return;
	if(l<=lft&&rit<=r){
		ptg(now,frc);
		return;
	}
	tgd[now]&&(pushdown(now),1);
	modify(lsn[now],lft,lrt[now],l,r,frc),modify(rsn[now],rlt[now],rit,l,r,frc);
	sum[now]=sum[lsn[now]]+sum[rsn[now]];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; ++i<=n; scanf("%d",a+i));
	build(1,1,n);
	for(int i=0,op,l,r,x; ++i<=m; ){
		scanf("%d%d%d",&op,&l,&r);
		switch(op){
			case 1:
				scanf("%d",&x);
				modify(1,1,n,l,r,quickpow(u,x));
				break;
			case 2:
				printf("%d\n",query(1,1,n,l,r));
				break;
		}
	}
	return 0;
}