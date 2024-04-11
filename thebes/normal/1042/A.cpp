#include <bits/stdc++.h>
using namespace std;

int n, m, arr[105], i, mn, mx;

int main(){
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
		scanf("%d",&arr[i]), mx=max(mx,arr[i]+m);
	sort(arr+1,arr+n+1);
	for(i=1;i<=n;i++){
		m -= arr[n]-arr[i];
		arr[i] = arr[n];
	}
	if(m<=0) printf("%d ",arr[n]);
	else printf("%d ",arr[n]+(int)ceil(m/(double)n));
	printf("%d\n",mx);
	return 0;
}