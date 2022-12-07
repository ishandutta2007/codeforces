#include<bits/stdc++.h>

using namespace std;

const int N=400005;
int n,a[N];

void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=0;
	long long ans=0;
	for (int i=1;i<=n+1;i++)
		ans+=abs(a[i]-a[i-1]);
	for (int i=1;i<=n;i++)
		if (a[i]>a[i-1]&&a[i]>a[i+1])
			ans-=min(a[i]-a[i-1],a[i]-a[i+1]); 
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}