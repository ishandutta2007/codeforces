#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
#define ll long long
int n;
int a[maxn];
ll s[maxn];
map<ll,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	ll ans=0;
	int lst=-1;
	mp[0]=0;
	for(int i=1;i<=n;++i)
	{
		if(mp.count(s[i]))lst=max(lst,mp[s[i]]);
		ans+=i-lst-1;
		mp[s[i]]=i;
	}
	cout<<ans<<endl;
}