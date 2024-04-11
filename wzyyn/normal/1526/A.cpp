#include<bits/stdc++.h>
using namespace std;
int n,a[55];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	for (int i=1;i<=n;i++)
		printf("%d %d ",a[i],a[i+n]);
	puts(""); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}