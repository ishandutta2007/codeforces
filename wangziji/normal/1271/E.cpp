#include <iostream>
#define int long long
using namespace std;
int n,k;
inline bool pd(int x)
{
	int a=1;
	while(a*x<=n)
		a*=2;
	a/=2;
	int t=(n-a*x)+1;
	t=min(t,a*2);
	int rtn=t+a*2-2;
	return rtn>=k;
}
inline bool Pd(int x)
{
	int a=1;
	while(a*x<=n)
		a*=2;
	a/=2;
	int t=(n-a*x)+1;
	t=min(t,a);
	int rtn=t+a-1;
	//cout << x << " " << rtn << endl;
	return rtn>=k;
}
signed main(int argc, char** argv) {
	cin >> n >> k;
	if(k==1)
	{
		cout << n;
		return 0;
	}
	if(k==n)
	{
		cout << 1;
		return 0;
	}
	int l=1,r=n/2,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pd(mid*2))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	ans*=2;
	int t=ans+1;
	while(Pd(t))
	{
		t+=2;
	}
	cout << max(t-2,ans);
	return 0;
}