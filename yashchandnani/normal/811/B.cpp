#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int l,r,x,count=0;
		cin>>l>>r>>x;
		for (int i = l-1; i < r; ++i)
		{
			if (a[i]<a[x-1])
			{
				count++;
			}
		}
		if (count==x-l)
		{
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}