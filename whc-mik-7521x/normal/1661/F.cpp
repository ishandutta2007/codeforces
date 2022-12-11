#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],b[N],n,m,sum,al,tot;
long long calc(long long a,long long k){return (a/k)*(a/k)*k+((a/k)*2+1)*(a%k);}
bool check(long long x){
	sum=al=0;
	for(int i=1;i<=n;i++){
		long long l=2,r=a[i],t=1;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(calc(a[i],mid-1)-calc(a[i],mid)>=x)t=mid,l=mid+1;
			else r=mid-1;
		}
		al+=calc(a[i],t);
		sum+=t-1;
	}
	return al<=m;
}
int main(){
    scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]),a[i]=b[i]-b[i-1],tot+=a[i]*a[i];
	scanf("%lld",&m);
	if(tot<=m)return puts("0"),0;
	long long l=1,r=1e18,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	printf("%lld",sum-(m-al)/ans);
    return 0;
}