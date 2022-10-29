#include <iostream>
#include <algorithm>
#define mod 998244353
#define int long long
using namespace std;
pair <int,int> a[200005];
int b[200005],cnt;
signed main(int argc, char** argv) {
//	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	int s=0;
	for(int i=n;i>=n-k+1;i--)
		s+=a[i].first,b[++cnt]=a[i].second;
	cout << s << " ";
	sort(b+1,b+k+1);
	int ans=1,lst=1;
	for(int i=1;i<k;i++)
		ans*=b[i+1]-b[i],ans%=mod;
	cout << ans;
	return 0;
}