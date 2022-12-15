#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int c[MN], n, i, x, ans;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		if(c[x-1]) c[x] = c[x-1]+1, c[x-1]=0;
		else c[x] = 1;
	}
	for(i=1;i<=1e5;i++)
		ans = max(ans, c[i]);
	printf("%d\n",n-ans);
	return 0;
}