#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,avx,mmx,abm,popcnt,tune=native")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MN = 1e5+5;
int arr[MN], n, m, i, j;
double ans=-1;

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(i=j=1;i<=n;i++){
		while(arr[j]-arr[i]<=m&&j<=n) j++;
		if(j-i<3) continue;
		ans = max(ans,(double)(arr[j-1]-arr[i+1])/(double)(arr[j-1]-arr[i]));
	}
	if(ans==-1) printf("-1\n");
	else printf("%.10lf\n",ans);
	return 0;
}