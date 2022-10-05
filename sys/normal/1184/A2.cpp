#include <bits/stdc++.h>
using namespace std;
char s[200020];
int n,calc[200020],getype[200020],qaq,mygcd[200020];
int gcd(int x,int y)
{
	return x==0?y:gcd(y%x,x);
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		calc[i]=s[i]^48;
	} 
	for(int i=1;i<=n;i++)
	{
		if(!(n%i))
		{
			qaq=1;
			for(int k=0;k<i;k++)
			{
				int sum=0;
				for(int j=k;j<n;j+=i)
				{
					sum^=calc[j];
				}
				if(sum>0)
				{
					qaq=0;
				}
			}
			getype[i]^=qaq;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		mygcd[i]=gcd(i,n);
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(getype[mygcd[i]]>0);
	}
	cout<<ans;
}