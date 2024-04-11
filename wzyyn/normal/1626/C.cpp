#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],b[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=n;i>1;i--)
		b[i-1]=max(b[i-1],b[i]+a[i-1]-a[i]);
	for (int i=1;i<=n;i++)
		if (b[i]>a[i]-a[i-1])
			b[i]=b[i-1]+a[i]-a[i-1];
	long long ans=0;
	for (int i=1;i<=n;i++)
		if (b[i]>a[i]-a[i-1]){
			int l=b[i-1]+1,r=b[i];
			ans=ans+1ll*(r+l)*(r-l+1)/2;
		}
		else{
			int l=1,r=b[i];
			ans=ans+1ll*(r+l)*(r-l+1)/2;
		}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}