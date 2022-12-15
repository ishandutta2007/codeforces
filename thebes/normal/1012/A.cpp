#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int arr[2*MN], N, i, x;
long long ans;

int main(){
	for(scanf("%d",&N),i=1;i<=2*N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+2*N+1);
	ans = 1LL*(arr[N]-arr[1])*(arr[2*N]-arr[N+1]);
	for(i=2;i<=N;i++){
		ans=min(ans,1LL*(arr[i+N-1]-arr[i])*(arr[2*N]-arr[1]));
	}
	printf("%lld\n",ans);
	getchar(); getchar();
	return 0;
}