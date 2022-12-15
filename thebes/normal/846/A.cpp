#include <bits/stdc++.h>
using namespace std;

int n, arr[101], i, j, ans;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=n;i++){
		int s=0;
		for(int j=i-1;j>=1;j--)
			if(!arr[j]) s++;
		for(int j=i+1;j<=n;j++)
			if(arr[j]) s++;
		ans = max(ans, s+1);
	}
	printf("%d\n",ans);
	return 0;
}