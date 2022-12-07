#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p=0;
	for (;p!=n&&a[p+1]<=0;++p);
	int mn=1<<30;
	for (int i=1;i+1<=p;i++)
		mn=min(mn,a[i+1]-a[i]);
	if (p!=n&&a[p+1]<=mn) ++p;
	cout<<p<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}