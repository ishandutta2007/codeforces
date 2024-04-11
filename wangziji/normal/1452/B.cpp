#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mx=0,s=0,cd=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			if(x>mx) cd=mx,mx=x;
			else if(x>cd) cd=x;
			s+=x;
		}
		int ans=mx*(n-1)-s;
		if(ans<0)
		{
			ans+=(-ans)/(n-1)*(n-1);
			while(ans<0) ans+=n-1;
		}
		cout << ans << "\n";
	}
	return 0;
}