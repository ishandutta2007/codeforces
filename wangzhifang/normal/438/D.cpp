#include <cstdio>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef long long ll;
#define max_n 100000
#define lowbit(x) (x&(-x))
ll a[max_n+1],v[max_n+1],mx[max_n+1];
il ll query(int p){
	ll ret=0;
	for(; p; p^=lowbit(p))
		ret+=a[p];
	return ret;
}
int n;
il void update(int p,const int&val){
	for(; p<=n; p+=lowbit(p)){
		a[p]+=val,mx[p]=v[p];
        for(int i=1; i<lowbit(p); i<<=1)
			mx[p]=max(mx[p],mx[p-i]);
	}
}
int main(){
	int m,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",v+i);
		for(mx[i]=a[i]=v[i],k=lowbit(i)>>1; k; k>>=1)
			a[i]+=a[i-k],mx[i]=max(mx[i],mx[i-k]);
	}
	for(int op,l,r,x; m; --m){
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			printf("%lld\n",query(r)-query(l-1));
			continue;
		}
		if(op==2){
			scanf("%d",&x);
			for(int j=r; j>=l; --j){
				if(mx[j]<x){
					j=j-lowbit(j)+1;
					continue;
				}
				if(v[j]>=x){
					k=v[j];
					v[j]%=x;
					update(j,v[j]-k);
				}
			}
		}
		else{
			k=v[l];
			v[l]=r;
			update(l,r-k);
		}
	}
	return 0;
}