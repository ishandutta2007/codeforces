#include <bits/stdc++.h>
using namespace std;

int d, arr[105], n, i, flag;
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	d = arr[2]-arr[1];
	for(i=2;i<n;i++){
		if(arr[i+1]-arr[i]!=d)
			flag = 1;
	}
	printf("%d\n",(flag)?arr[n]:arr[n]+d);
	return 0;
}