#include<bits/stdc++.h>

using namespace std;

int n,a[105],b[105];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) if (a[i]<b[i]) swap(a[i],b[i]);
	printf("%d\n",(*max_element(a+1,a+n+1))*(*max_element(b+1,b+n+1)));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}