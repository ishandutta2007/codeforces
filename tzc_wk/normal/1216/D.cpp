#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[2]-a[1],ans=0;
	for(int i=2;i<n;i++)	x=__gcd(x,a[i+1]-a[i]);
	for(int i=1;i<n;i++)	ans+=(a[n]-a[i])/x;
	cout<<ans<<" "<<x<<endl;
	return 0;
}