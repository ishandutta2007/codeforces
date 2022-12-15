#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define eps 1e-12

int n, k, i, j;
double lo, hi, arr[5005], psa[5005];
bool check(double m){
	for(i=1;i<=n;i++)
		psa[i]=psa[i-1]+arr[i]-m;
	for(i=1;i<=n;i++){
		for(j=i+k-1;j<=n;j++){
			if(psa[j]-psa[i-1]>=0)
				return 1;
		}
	}
	return 0;
}

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
		scanf("%lf",&arr[i]);
	lo = 1; hi = 5000;
	while(lo+eps<hi){
		double m=(lo+hi)/2;
		if(check(m)) lo=m+eps;
		else hi=m;
	}
	printf("%.10lf\n",lo);
	getchar(); getchar();
}