#include<bits/stdc++.h>

using namespace std;

int n,a[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=2;i<=n/2+1;i++)
		printf("%d %d\n",a[i],a[1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}