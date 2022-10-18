#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[105];
int n;
bool cmp(int x)
{
	int tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=a[i];
		if(tmp==x)
		{
			tmp=0;
		}
		if(tmp>x)
		{
			return false;
		}
//		cout<<tmp<<endl;
	}
	if(tmp!=0)
	{
		return false;
	}
	return true;
}
int main()
{
	
	cin>>n;
	if(n==1)
	{
		cout<<"NO\n";
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
		sum+=a[i];
	}
//	cout<<sum<<endl;
	if(sum==0)
	{
		cout<<"YES\n";
		return 0;
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(sum%i==0)
		{
//			cout<<i<<endl;
			if(cmp(i)==true)
			{
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}