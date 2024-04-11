#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> va,vb;
int main()
{
	ll a,b;
	cin>>a>>b;
	ll ans=0;
	while((ans+2)*(ans+1)<=(a+b)*2)
	{
		ans++;
	}
	for(int i=ans;i>0;i--)
	{
		if(a>=i)
		{
			va.push_back(i);
			a-=i;
		}
		else if(b>=i)
		{
			vb.push_back(i);
			b-=i;
		}
	}
	printf("%d\n",va.size());
	for(int i=0;i<va.size();i++)
	{
		printf("%d ",va[i]);
	}
	cout<<"\n";
	printf("%d\n",vb.size());
	for(int i=0;i<vb.size();i++)
	{
		printf("%d ",vb[i]);
	}
	return 0;
}