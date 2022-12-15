#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
long long ans=0, n, m, i, x, tot, arr[MN], ex;

int main(){
	for(scanf("%lld%lld",&n,&m),i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	arr[n+1] = m;
	for(i=1;i<=n+1;i+=2)
		tot += arr[i]-arr[i-1];
	ans = tot;
	for(i=0;i<=n;i++){
		if(arr[i+1]-arr[i]>1){
			if(i%2==0){
				tot -= arr[i+1]-arr[i]; 
				ans = max(ans,arr[i+1]-arr[i]-1+m-arr[i+1]-tot+ex);
				ex+=arr[i+1]-arr[i];
			}
			else{
				ans = max(ans,arr[i+1]-arr[i]-1+m-arr[i+1]-tot+ex);
			}
		}
		else if(i%2==0){
			tot -= arr[i+1]-arr[i];
			ex += arr[i+1]-arr[i];
		}
	}
	printf("%lld\n",ans);
	getchar(); getchar();
}