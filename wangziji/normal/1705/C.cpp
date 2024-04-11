#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<pair<int,int>,int> > v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		v.clear();
		int n,c,q;
		cin >> n >> c >> q;
		string s;
		cin >> s;
		int nw=s.size();
		for(int i=1;i<=c;i++)
		{
			int l,r;
			cin >> l >> r;
			--l,--r;
			int L=nw,R=nw+r-l;
			v.push_back({{L,R},L-l});
			nw+=r-l+1;
		}
		while(q--)
		{
			int x;
			cin >> x;
			--x;
			while(x>=n)
			{
				for(auto t:v)
				{
					if(x<=t.first.second&&x>=t.first.first)
					{
						x-=t.second;
						break;
					}
				}
			}
			cout << s[x] << "\n";
		}
	}
	return 0;
 }