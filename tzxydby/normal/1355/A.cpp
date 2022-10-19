#include<bits/stdc++.h>
#define int long long
using namespace std;
int zero(int x)
{
	while(x)
	{
		if(x%10==0)
			return 1;
		x/=10;
	}
	return 0;
}
int mi(int x)
{
	int a=9;
	while(x)
	{
		a=min(a,x%10);
		x/=10;
	}
	return a;
}
int ma(int x)
{
	int a=0;
	while(x)
	{
		a=max(a,x%10);
		x/=10;
	}
	return a;
}
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		k--;
		while(k--)
		{
			if(zero(n))
				break;
			n+=mi(n)*ma(n);
		}
		cout<<n<<endl;
	}
	return 0;
}