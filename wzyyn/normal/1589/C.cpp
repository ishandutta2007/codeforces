#include<bits/stdc++.h>

using namespace std;

int n,a[105],b[105];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	bool fl=1;
	for (int i=1;i<=n;i++)
		if (a[i]!=b[i]&&a[i]+1!=b[i])
			fl=0;
	puts(fl?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}