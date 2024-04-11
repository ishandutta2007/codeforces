#include<bits/stdc++.h>

using namespace std;

int n,a[10005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
		if (a[i]>a[i+1])
			return puts("YES"),void(0);
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}