#include <bits/stdc++.h>
using namespace std;

const int MN = 5e5+5;
int arr[MN], d[MN], n, i, j, x, ans;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=2;i<n;i++){
		if(arr[i-1]!=arr[i]&&arr[i]!=arr[i+1])
			d[i] = d[i-1]+1;
	}
	for(i=n;i>=2;i--){
		if(arr[i-1]!=arr[i]&&arr[i]!=arr[i+1])
			d[i] = min(d[i],d[i+1]+1);
	}
	for(i=n;i>=2;i--){
		ans = max(ans, d[i]);
		if(d[i]%2) arr[i]=!arr[i];
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		printf("%d ",arr[i]);
	return 0;
}