#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200005],n,ans;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=2*n-1;
	for (int i=1;i+2<=n;i++){
		if (a[i+1]<a[i]&&a[i+1]<a[i+2]) ++ans;
		if (a[i+1]>a[i]&&a[i+1]>a[i+2]) ++ans;
	}
	for (int i=1;i+3<=n;i++){
		if (a[i+1]<a[i]&&a[i+1]<a[i+3]&&a[i]<a[i+2]&&a[i+3]<a[i+2]) ++ans;
		if (a[i+1]>a[i]&&a[i+1]>a[i+3]&&a[i]>a[i+2]&&a[i+3]>a[i+2]) ++ans;
	}
	cout<<ans<<endl;
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}