#include <bits/stdc++.h>
using namespace std;

int arr[361], N, ans = 360, i, j, p;

int main(){
	for(scanf("%d",&N);i<N;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<N;i++,p=0){
		p += arr[i]; ans=min(2*abs(p-180),ans);
		for(j=(i+1)%N;j!=i;j=(j+1)%N){
			p += arr[j]; ans=min(2*abs(p-180),ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}