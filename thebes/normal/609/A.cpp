#include <bits/stdc++.h>
using namespace std;

int N, M, arr[101], i;
bool cmp(int i, int j){return(i>j);}

int main(){
	for(scanf("%d%d",&N,&M);i<N;i++)
		scanf("%d",&arr[i]);
	sort(arr, arr+N, cmp);
	for(i=0;i<N;i++){
		M -= arr[i];
		if(M <= 0) break;
	}
	printf("%d\n",i+1);
	return 0;
}