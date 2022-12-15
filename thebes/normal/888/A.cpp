#include <bits/stdc++.h>
using namespace std;

int arr[1003], N, ans, i;

int main(){
	for(scanf("%d",&N),i=0;i<N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<N-1;i++){
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) ans++;
		if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}