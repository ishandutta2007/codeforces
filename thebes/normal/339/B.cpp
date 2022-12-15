#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, m, i, x, y, p=1;

int main(){
	for(scanf("%d%d",&n,&m);i<m;i++){
		scanf("%d",&x);
		ans += (x-p+n)%n;
		p = x;
	}
	printf("%lld\n",ans);
	return 0;
}