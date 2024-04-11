#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[205]={0};
		for(int i=0;i<n;i++)
		{
			int k;
			cin>>k;
			a[k]=1;
		}
		int i=1,coun=0;
		while(coun<x)
		{
			if(a[i]==0) 
			{
				a[i]=1;
				coun++;
			}
			i++;
		}
		int ans=0;
		for(i=1;i<205;i++)
		{
			if(a[i]==0) break;
			ans++;
		}
		cout<<ans<<"\n";
	}
}