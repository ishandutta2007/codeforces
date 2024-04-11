#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"No\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(a[1]%2==0||a[n]%2==0)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}