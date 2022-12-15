#include <bits/stdc++.h>
using namespace std;

int N, i, a, x, y, arr[101];
int main(){
	for(scanf("%d",&N),i=1;i<=N/2;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+N/2+1);
	for(i=1;i<=N/2;i++){
		x += abs(2*i-1-arr[i]);
		y += abs(2*i-arr[i]);
	}
	printf("%d\n",min(x,y));
	return 0;
}