#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=1000005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,a[N],b[N],c[N];
LL ans=INFLL;
LL sol(LL p){
	D("p=%lld\n",p);
	rep(i,1,n){
		b[i]=a[i];
	}
	LL res=0;
	for(int i=1,j=0;i<=n;i=max(i,j-1)){
		b[i]%=p;
		if(b[i]==0){++i;continue;}
		j=i;
		LL sum=0;
		while(j<=n&&sum<p){
			if(sum+b[j]<=p){
				c[j]=b[j];
			}else{
				c[j]=p-sum;
			}
			sum+=c[j];
			b[j]-=c[j];
			++j;
		}
		int j_=i;
		LL sum_=0;
		while(j_<=n&&sum_<(p+1)/2){
			sum_+=c[j_];
			++j_;
		}
		rep(k,i,j-1){
			res+=1LL*c[k]*abs(k-(j_-1));
		}
		rep(k,i,j-1){
			c[k]=0;
		}
	}
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	LL sum=0;
	rep(i,1,n)scanf("%d",&a[i]),sum+=a[i];
	if(sum<=1)puts("-1"),exit(0);
	rep(i,2,sum/i)if(sum%i==0){
		ans=min(ans,sol(i));
		while(sum%i==0)sum/=i;
	}
	if(sum>1){
		ans=min(ans,sol(sum));
	}
	printf("%lld\n",ans);
	return 0;
}