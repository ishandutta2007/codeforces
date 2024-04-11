#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		stable_sort(a+1,a+n+1);
		long long s1=a[n]*(n-2)+sum,s2=a[1]*(n-2)+sum;
		if(s1<0||s2>0){
			puts("INF");
		}
		else{
			long long k=a[n]*(n-2)+sum;
			long long y=(n-1)*a[n]*a[n]*-1;
			long long ans=y;
			for(long long i=2;i<=n;i++){
				y+=k*(a[n-i+2]-a[n-i+1]);
				ans=max(y,ans);
				k+=a[1]-a[n];
			}
			printf("%lld\n",ans);
		}
	}
}