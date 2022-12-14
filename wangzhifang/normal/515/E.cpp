#include <cstdio>
#include <algorithm>
#define cs const
#define max_n 100000
#define max_log_n 17
#define INF 9223372036854775807ll
using namespace std;
typedef long long ll;
ll a[max_n<<1|1],b[max_n<<1|1];
//namespace sparse_table{
//	typedef cs int& ci;
//	template<typename T>void init(T*a,ci n,T(*st)[18],cs T&(*func)(cs T&x,cs T&y)){
//		for(int i=0; ++i<=n; st[i][0]=a[i]);
//		for(int i=0,bas=1,hbs=1,x=0; ++i,(bas<<=1)<=n; x=i,hbs=bas)
//			for(T(*j)[18]=&st[n-bas+2]; --j>st; (*j)[i]=func((*j)[x],*(j+hbs)[x]));
//	}
//	template<typename T>T query(T(*st)[18],ci l,ci r,cs T&(*func)(cs T&x,cs T&y)){
//		int k=31-__builtin_clz(r-l);
//		return func(st[l][k],st[r-(1<<k)+1][k]);
//	}
//}
typedef cs int& ci;
template<typename T>void init(T*a,ci n,T(*st1)[max_log_n+2],int(*pos)[max_log_n+2],T(*st2)[max_log_n+2]){
	for(int i=0; ++i<=n; st1[i][0]=a[i],pos[i][0]=i,st2[i][0]=-INF);
	for(int i=0,bas=1,hbs=1,x=0; ++i,(bas<<=1)<=n; x=i,hbs=bas)
		for(int j=n-bas+2,k; --j; st1[j][x]>st1[k=j+hbs][x]?(st1[j][i]=st1[j][x],pos[j][i]=pos[j][x],st2[j][i]=max(st2[j][x],st1[k][x])):(st1[j][i]=st1[k][x],pos[j][i]=pos[k][x],st2[j][i]=max(st1[j][x],st2[k][x])));
}
template<typename T>void query(T(*st)[max_log_n+2],T(*st2)[max_log_n+2],int l,ci r,T&fst,T&scd){
	int k=32-__builtin_clz(r-l+1);
	fst=scd=-INF;
	for(int tmp; l<=r; l+=tmp){
		(tmp=1<<(--k))+l>(r+1)&&(tmp=1<<(k=31-__builtin_clz(r-l+1)));
		if(st[l][k]>fst){
			scd=max(fst,st2[l][k]);
			fst=st[l][k];
		}
		else
			st[l][k]>scd&&(scd=st[l][k]);
	}
}
template<typename T>int query1(T(*st)[max_log_n+2],int(*pos)[max_log_n+2],ci l,ci r,T&x){
	int k=31-__builtin_clz(r-l+1),tmp;
	if(st[l][k]>=st[tmp=r-(1<<k)+1][k])
		return x=st[l][k],pos[l][k];
	else
		return x=st[tmp][k],pos[tmp][k];
}
ll sta[max_n<<1|1][max_log_n+2],stb[max_n<<1|1][max_log_n+2];
int posa[max_n<<1|1][max_log_n+2],posb[max_n<<1|1][max_log_n+2];
ll st2a[max_n<<1|1][max_log_n+2],st2b[max_n<<1|1][max_log_n+2];
int main(){
	int n,m;
	scanf("%d%d",&n,&m),a[1]=0;
	long long*ed=a+n;
	for(long long*i=a,x; ++i<=ed; *(i+1)=*i+x)
		scanf("%lld",&x);
	ll s=a[n+1];
	for(long long*i=a+1; ++i<=ed; *(i+n)=*i+s);
	for(int i=0,x; ++i<=n; a[i]+=x,a[i+n]+=x){
		scanf("%d",&x);
		b[i]=(x<<=1)-a[i];
		b[i+n]=x-a[i+n];
	}
	init(a,n<<1,sta,posa,st2a);
	init(b,n<<1,stb,posb,st2b);
	ll fsta,scda,fstb,scdb;
	for(int i=m+1,l,r; --i; ){
		scanf("%d%d",&l,&r);
		swap(--l,++r);
		l>r&&(r+=n);
		if(query1(sta,posa,l,r,fsta)!=query1(stb,posb,l,r,fstb))
			printf("%lld\n",fsta+fstb);
		else{
			query(sta,st2a,l,r,fsta,scda),
			query(stb,st2b,l,r,fstb,scdb);
			printf("%lld\n",max(fsta+scdb,fstb+scda));
		}
	}
	return 0;
}