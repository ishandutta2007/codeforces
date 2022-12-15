#include <bits/stdc++.h>
using namespace std;

const int MN = 5e3+5;
int arr[MN], N, i, x, y;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	sort(arr+1, arr+N+1);
	for(i=N;i>=1;i--){
		if(arr[i]!=arr[i+1]) y+=x,x=0;
		x++; if(y) y--;
	}
	printf("%d\n",x+y);
	return 0;
}