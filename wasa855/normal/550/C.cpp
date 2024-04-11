#include<bits/stdc++.h>
using namespace std;
int a[105];
string s;
int main()
{
	cin>>s;
	int n=s.length();
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]%8==0)
		{
			cout<<"YES\n";
			cout<<a[i]<<endl;
			return 0;
		}
		if(a[i]==0)
		{
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]*10+a[j])%8==0)
			{
				cout<<"YES\n";
				cout<<(a[i]*10+a[j])<<endl;
				return 0;
			}
			for(int k=j+1;k<=n;k++)
			{
				if((a[i]*100+a[j]*10+a[k])%8==0)
				{
					cout<<"YES\n";
					cout<<(a[i]*100+a[j]*10+a[k])<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}