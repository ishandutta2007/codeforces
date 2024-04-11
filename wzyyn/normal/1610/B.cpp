#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
bool check(int x){
	int l=1,r=n;
	for (;l<=r;){
		for (;a[l]==x&&l<=r;++l);
		for (;a[r]==x&&l<=r;--r);
		if (l>r) return 1;
		if (a[l]!=a[r]) return 0;
		++l; --r;
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=n;
	for (;l<=r&&a[l]==a[r];++l,--r);
	if (l>r) puts("YES");
	else puts(check(a[l])||check(a[r])?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}