#include <bits/stdc++.h>
using namespace std;

int arr[102], t, N, K, X, i;

int main(){
	for(scanf("%d%d%d",&N,&K,&X),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1, arr+N+1);
	for(i=N;i>=1;i--){
		if(i >= max(1,N-K+1)) t += min(arr[i],X);
		else t += arr[i];
	}
	printf("%d\n",t);
	return 0;
}