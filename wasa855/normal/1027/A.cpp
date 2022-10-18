#include<bits/stdc++.h>
using namespace std;
void work()
{
	int m;
	cin>>m;
	char a[105];
	scanf("\n%s",a+1);
	for(int i=1;i<=m/2;i++)
	{
		if(!(a[i]==a[m-i+1]||abs(a[i]-a[m-i+1])==2))
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	return ;
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		work();
	}
	return 0;
}