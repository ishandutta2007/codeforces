#include <bits/stdc++.h>
using namespace std;

int arr[105], N, i, j, k;
int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=N;i++){
		for(int j=N;j>1;j--){
			if(arr[j]<arr[j-1]){
				printf("%d %d\n",j-1,j);
				swap(arr[j-1],arr[j]);
			}
		}
	}
	return 0;
}