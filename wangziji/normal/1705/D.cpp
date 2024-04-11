#include <bits/stdc++.h>
#define int long long
using namespace std;
int D(int x,int y)
{
	return max(x,y)-min(x,y);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		vector<pair<int,int> > a,b;
		cin >> n;
		string s,t;
		cin >> s >> t;
		if(s[0]!=t[0]||s.back()!=t.back())
		{
			cout << "-1\n";
			continue;
		}
		int l=-1,r=-2;
		s+='0',t+='0';
		for(int i=0;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(r==i-1) r=i;
				else l=r=i;
			}
			else if(s[i]=='0')
				if(r==i-1) a.push_back({l,r});
		}
		l=-1,r=-2;
		for(int i=0;i<=n;i++)
		{
			if(t[i]=='1')
			{
				if(r==i-1) r=i;
				else l=r=i;
			}
			else if(t[i]=='0')
				if(r==i-1) b.push_back({l,r});
		}
		if(a.size()!=b.size())
		{
			cout << "-1\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<a.size();i++)
		{
			ans+=D(a[i].first,b[i].first);
			ans+=D(a[i].second,b[i].second);
		}
		cout << ans << "\n";
	}
	return 0;
 }