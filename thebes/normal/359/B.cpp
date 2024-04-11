#include <bits/stdc++.h>
using namespace std;

int n, k, i;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n&&i<=k;i++)
		printf("%d %d ",2*i,2*i-1);
	for(;i<=n;i++)
		printf("%d %d ",2*i-1,2*i);
	return 0;
}