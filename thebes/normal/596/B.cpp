#include <bits/stdc++.h>
using namespace std;

long long ans;
int tot, b[200005], n, i;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++){
		ans += abs(b[i]-tot);
		tot = b[i];
	}
	printf("%lld\n",ans);
	return 0;
}