#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int arr[MN][MN], N, K, c, i, j, h[MN], ans;
bool can(int p){
	if(h[p]>N) return 0;
	if(p==1) return 1;
	else return(h[p]<h[p-1]);
}

int main(){
	scanf("%d%d",&N,&K);
	for(i=1;i<=N;i++) h[i]=1;
	for(i=1;i<=N*N;i++){
		for(j=1;j<=N;j++){
			if(j==K) continue;
			if(can(j)){
				arr[j][h[j]]=i;h[j]++;
				goto next;
			}
		}
		arr[K][h[K]]=i; ans+=i;
		h[K]++;
	next:;
	}
	printf("%d\n",ans);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			printf("%d ",arr[j][i]);
		printf("\n");
	}
	return 0;
}