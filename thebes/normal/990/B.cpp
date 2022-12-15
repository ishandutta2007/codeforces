#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+6;
int arr[MN], N, K, i, ans, idk[MN];

int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+N+1);
	for(i=1;i<=N;i++){
		int a=lower_bound(arr+1,arr+i,arr[i])-arr;
		int b=lower_bound(arr+1,arr+i,arr[i]-K)-arr;
		idk[b]++; idk[a]--;
	}
	for(i=1;i<=N;i++){
		idk[i] += idk[i-1];
		if(!idk[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}