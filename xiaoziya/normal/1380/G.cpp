#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=300005,mod=998244353;
int n,invn;
int a[maxn],sum[maxn];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
inline int cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n),invn=ksm(n,mod-2);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=(sum[i-1]+a[i])%mod;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;;j++){
			int k=j*i+i;
			ans=(ans+1ll*(sum[min(k,n)]-sum[j*i]+mod)*j)%mod;
			if(k>=n)
				break;
		}
		printf("%d%c",(int)(1ll*ans*invn%mod),i==n? '\n':' ');
	}
	return 0;
}