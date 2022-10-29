#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		v.clear();
		if(a<b) swap(a,b);
		int l=0,r=a+b;
		while(a>b+1) ++l,--r,a-=2;
		if(a==b)
			for(int i=l;i<=r;i+=2) v.push_back(i);
		else for(int i=l;i<=r;i++) v.push_back(i);
		cout << v.size() << "\n";
		for(auto t:v) cout << t << " ";
		cout << "\n";
	}
	return 0;
}