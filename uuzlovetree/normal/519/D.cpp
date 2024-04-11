#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int a[maxn];
int n;
char s[maxn];
ll sum[maxn];
ll cnt;
map<ll,ll> mp;
int main()
{
	for(int i=1;i<=26;++i)scanf("%d",&a[i]);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+1ll*a[s[i]-'a'+1];
	ll ans=0;
	for(int c=1;c<=26;++c)
	{
		mp.clear();
		for(int i=1;i<=n;++i)if(c==s[i]-'a'+1)
		{
			ans+=mp[sum[i]-a[c]];
			mp[sum[i]]++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}