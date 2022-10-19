#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>ql;
priority_queue<int,vector<int>,greater<int>>qr;
int n,s;
vector<pair<int,int>>a;
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a.emplace_back(x+y,x-y);
	}
	sort(a.begin(),a.end());
	ql.push(0),qr.push(0);
	for(auto [y,x]:a)
	{
		s+=max(max(ql.top()-x-y,-qr.top()+x-y),0LL);
		if(qr.top()+y>x||!ql.size())
		{
			ql.push(x+y);
			ql.push(x+y);
			qr.push(ql.top()-2*y);
			ql.pop();
		}
		else
		{
			qr.push(x-y);
			qr.push(x-y);
			ql.push(qr.top()+2*y);
			qr.pop();
		}
	}
	cout<<s/2<<endl;
	return 0;
}