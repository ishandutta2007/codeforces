#include<bits/stdc++.h>
using namespace std;

int n,a[105];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p=1;
	for (;p<=n&&a[p]==a[1];++p);
	cout<<n-p+1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}