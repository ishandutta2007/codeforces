#include <bits/stdc++.h>
using namespace std;

int n, m, arr[11], f[11], ans, i, x;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		f[x] = 1;
	}
	for(i=1;i<=n;i++)
		if(f[arr[i]]) printf("%d ",arr[i]);
	return 0;
}