#include<bits/stdc++.h>
using namespace std;
string s="aeiou",ans="";
int main()
{
	int k,n=-1,m=-1;
	cin>>k;
	for(int i=5;i<=k;i++)
	{
		if(k%i==0&&k/i>=5)
		{
			n=i;
			m=k/i;
			break;
		}
	}
	if(n==-1)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int t=1;
		for(int j=(i-1)%5;t<=m;j=(j+1)%5,t++)
			ans+=s[j];
	}
	cout<<ans<<endl;
	return 0;
}