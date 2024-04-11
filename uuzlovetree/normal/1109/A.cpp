#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
int n;
int a[maxn],s[maxn];
map<int,int> mp1,mp2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	for(int i=0;i<=n;++i)
	{
		if(i&1)mp1[s[i]]++;
		else mp2[s[i]]++;
	}
	map<int,int>::iterator it;
	ll ans=0;
	for(it=mp1.begin();it!=mp1.end();++it)
	{
		ll x=it->second;
		ans+=x*(x-1)/2;
	}
	for(it=mp2.begin();it!=mp2.end();++it)
	{
		ll x=it->second;
		ans+=x*(x-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}