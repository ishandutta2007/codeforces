#include <bits/stdc++.h>
using namespace std;

int n, f[5005], i;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&f[i]);
	for(i=1;i<=n;i++)
		if(f[f[f[i]]]==i){printf("YES\n"); return 0;}
	printf("NO\n");
	return 0;
}