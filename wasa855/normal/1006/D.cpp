#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	char c,d,e,f;
	int l=n/2;
	int ans=0;
	for(int i=0;i<l;i++)
	{
		c=a[i];
		d=b[i];
		e=a[n-i-1];
		f=b[n-i-1];
		map<char,int> mp;
		mp[c]++;
		mp[d]++;
		mp[e]++;
		mp[f]++;
//		printf("%c %c %c %c\n",c,d,e,f);
		if(mp.size()==2)
		{
			if(mp[c]==3||mp[c]==1)
			{
				ans++;
			}
		}
		if(mp.size()==3)
		{
			if(a[i]==a[n-i-1])
			{
				ans+=2;
			}
			else
			{
				ans++;
			}
		}
		if(mp.size()==4)
		{
			ans+=2;
		}
	}
	if(n%2==1)
	{
		if(a[n/2]!=b[n/2])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}