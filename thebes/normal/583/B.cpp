#include <bits/stdc++.h>
using namespace std;

int N, i, arr[1003], cnt, inf, p, ans;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	while(cnt < N){
		int d = (p==0)? 1:-1;
		for(p+=d;p>=1&&p<=N;p+=d){
			if(arr[p] <= inf){
				inf++; arr[p]=1<<30;
				cnt++;
			}
		}
		ans++;
	}
	printf("%d\n",ans-1);
	return 0;
}