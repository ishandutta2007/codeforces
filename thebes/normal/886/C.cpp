#include <bits/stdc++.h>
using namespace std;

int arr[200005], N, i, x, ans;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&x);
		if(arr[x]){arr[x]--; arr[i]++;}
		else{ans++; arr[i]++;}
	}
	printf("%d\n",ans);
	return 0;
}