#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int N, K, arr[MN], i, j, tot, ans, opt;
long long wow;
int main(){
	for(scanf("%d%d",&N,&K),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+N+1);
	for(i=j=1;i<=N;i++){
		wow += arr[i];
		for(;1LL*arr[i]*(i-j+1)-wow>K;j++)
			wow -= arr[j];
		if(i-j+1>ans){
			ans = i-j+1;
			opt = arr[i];
		}
	}
	printf("%d %d\n",ans,opt);
	return 0;
}