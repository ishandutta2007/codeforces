#include <bits/stdc++.h>
using namespace std;

int n, m, k, oc[2002][2002], i, j, c;
long long ans;

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=1;i<=n;i++){
		for(getchar(),j=1;j<=m;j++){
			int x = (getchar()=='*');
			oc[j][i] = x;
		}
	}
	for(i=1;i<=n;i++){
		c = 0;
		for(j=1;j<=m;j++){
			if(oc[j][i]) c = 0;
			else c++;
			if(c >= k) ans++;
		}
	}
	for(i=1;i<=m;i++){
		c = 0;
		for(j=1;j<=n;j++){
			if(oc[i][j]) c = 0;
			else c++;
			if(c >= k) ans++;
		}
	}
	if(k==1) ans/=2;
	printf("%lld\n",ans);
	return 0;
}