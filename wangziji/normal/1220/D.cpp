#include <iostream>
#define mod 121621
#define int long long
using namespace std;
int a[200005],b[200005];
inline int lowbit(int x)
{
	return x&(-x);
}
signed main(int argc, char** argv) {
	int n,ans=0,w=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		int t=lowbit(a[i]);
		b[t%mod]++;
		if(b[t%mod]>ans)
			ans=b[t%mod],w=t;
	}
	cout << n-ans << endl;
	for(int i=1;i<=n;i++)
	{
		if(lowbit(a[i])!=w)
			cout << a[i] << " ";
	}
	return 0;
}