#include <bits/stdc++.h>
#define int long long
using namespace std;
multiset <int> s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >> x;
		s.clear();
		for(int i=1;i<=n;i++)
		{
			int k;
			cin >> k;
			s.insert(k);
		}
		int ans=0;
		while(s.size())
		{
			int k=*s.begin();
			if(s.find(k*x)!=s.end())
			{
				s.erase(s.find(k*x));
			}
			else ++ans;
			s.erase(s.begin());
		}
		cout << ans << "\n";
	}
	return 0;
}