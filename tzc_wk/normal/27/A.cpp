#include <bits/stdc++.h>
using namespace std;
bool vis[3010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		vis[a]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<n+1<<endl;
	return 0;
}