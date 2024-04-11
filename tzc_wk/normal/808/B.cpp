#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200005],sum;
double ans;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=0;i<k;i++)	sum+=a[i];
	for(int i=1;i<=n-k+1;i++){
		sum-=a[i-1];
		sum+=a[i+k-1];
		ans+=sum*1.0/(n-k+1);
	}
	cout<<setprecision(20)<<ans<<endl;
	return 0;
}