#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505],n,b[505];
vector <pair<int,int> > op;
vector <int> sz;
inline bool solve(int x,int add)
{
	if(!x) return 1;
	for(int i=2;i<=x;i++)
	{
		if(a[i]==a[1])
		{
			int qwq=i;
			for(int j=2;j<i;j++)
			{
				op.push_back({qwq+add,a[j]});
				++qwq;
			}
			sz.push_back((i-1)*2);
			int nx=0;
			for(int j=i-1;j>=2;j--)
				b[++nx]=a[j];
			for(int j=i+1;j<=x;j++)
				b[++nx]=a[j];
			swap(a,b);
			return solve(nx,add+(i-1)*2);
		}
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		op.clear(),sz.clear();
		if(!solve(n,0))
		{
			cout << -1 << "\n";
			continue;
		}
		cout << op.size() << "\n"; 
		for(auto t:op)
			cout << t.first << " " << t.second << "\n";
		cout << sz.size() << "\n"; 
		for(auto t:sz)
			cout << t << " ";
		cout << "\n";
	}
	return 0;
}