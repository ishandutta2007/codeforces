#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int arr[MN], ans=1<<30, n, i, x;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	x = (n-2)/2;
	for(i=1;i<=(n-2)/2+1;i++){
		int r = x-i+1;
		ans = min(ans, arr[n-r]-arr[i]);
	}
	printf("%d\n",ans);
	return 0;
}