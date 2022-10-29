#include <iostream>
#define int long long
using namespace std;
long long a,b,c,d;
inline int cal(int x)
{
	int rtn=x*a;
	int qwq=min(c/d,x-1),qaq=(x-1-qwq)*b*c;
	qwq=qwq*(qwq+1)/2*b*d;
	return rtn-qwq-qaq;
}
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> a >> b >> c >> d;
		if(a>b*c)
		{
		    cout << -1 << "\n";
			continue;
		}
		int l=0,r=2000000,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(cal(mid)<cal(mid+1)) ans=max(ans,cal(mid+1)),l=mid+1;
			else ans=max(ans,cal(mid)),r=mid-1;
		}
		cout << ans << "\n";
	}
	return 0;
}