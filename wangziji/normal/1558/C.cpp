#include <bits/stdc++.h>
using namespace std;
int p[5005];
vector <int> v;
inline void rev(int x)
{
	v.push_back(x);
	reverse(p+1,p+x+1);
}
inline void solve(int n)
{
	if(n==1) return ;
	int a=0,d=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==n) a=i;
		if(p[i]==n-1) d=i;
	}
	if(a!=1) rev(a);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==n) a=i;
		if(p[i]==n-1) d=i;
	}
	rev(d-1);
	a=d-1;
	rev(d+1);
	rev(3);
	rev(n);
}
signed main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		v.clear();
		for(int i=1;i<=n;i++) cin >> p[i];
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]%2!=i%2)
			{
				cout << "-1\n";
				flag=1;
				break;
			}
		}
		if(flag) continue;
		for(int i=n;i>=1;i-=2)
			solve(i);
	//	for(int i=1;i<=n;i++) cerr << p[i] << " ";
	//	cerr << "\n";
		cout << v.size() << "\n";
		for(auto t:v) cout << t << " ";
		cout << "\n";
	}
	return 0;
}
/*
100
9
9 4 1 6 7 2 5 8 3
*/