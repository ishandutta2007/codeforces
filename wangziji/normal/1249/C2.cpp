#include <iostream>
#define int unsigned long long
using namespace std;
int inf=2e18;
inline int cal(int x)
{
	int base=1,ans=0;
	while(x)
	{
		if(x&1) ans+=base;
		base*=3;
		if(ans>inf)
			return inf;
		x>>=1;
	}
	return ans;
}
signed main() {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int l=0,r=1e18,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(cal(mid)>=n)
				ans=mid,r=mid-1;
			else
				l=mid+1;
			//cout << cal(ans) << " ";
		}
		cout << cal(ans) << endl;
	}
	return 0;
}