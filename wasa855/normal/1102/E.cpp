#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
int a[200005];
map<int,int> las;
map<int,int> fir;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(fir[a[i]]==0)
		{
			fir[a[i]]=i;
		}
		las[a[i]]=i;
	}
	ll ans=1;
	int end=1;
	bool used=false;
	for(int i=1;i<=n;i++)
	{
		if(las[a[i]]>end)
		{
			end=las[a[i]];
		}
		if(end==i)
		{
			if(used==false)
			{
				used=true;
				end++;
				continue;
			}
			ans=ans*2%mod;
			end++;
		}
	}
	cout<<ans<<endl;
	return 0;
}