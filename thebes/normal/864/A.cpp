#include <bits/stdc++.h>
using namespace std;

int cnt[101], N, i, j, x;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		scanf("%d",&x); cnt[x]++;
	}
	for(i=1;i<=100;i++){
		for(j=i+1;j<=100;j++){
			if(cnt[i] == cnt[j] && cnt[i]+cnt[j]==N){
				printf("YES\n%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}