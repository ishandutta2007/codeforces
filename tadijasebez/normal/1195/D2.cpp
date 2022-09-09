#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int L=11;
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int po[N];
int sum[L],cnt[L];
int GetA(int x, int l)
{
	int m=10,t=1,ans=0;
	while(l--)
	{
		if(x==0) break;
		ans=add(ans,mul(m,x%10));
		x/=10;
		m=mul(m,100);
		t=mul(t,100);
	}
	if(x) ans=add(ans,mul(t,x));
	return ans;
}
int GetB(int x, int l)
{
	int m=1,ans=0;
	while(l--)
	{
		if(x==0) break;
		ans=add(ans,mul(m,x%10));
		x/=10;
		m=mul(m,100);
	}
	if(x) ans=add(ans,mul(m,x));
	return ans;
}
int GetL(int x){ int ans=0;while(x) x/=10,ans++;return ans;}
int a[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		int l=GetL(a[i]);
		cnt[l]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<L;j++)
		{
			ans=add(ans,mul(cnt[j],GetA(a[i],j)));
			ans=add(ans,mul(cnt[j],GetB(a[i],j)));
		}
	}
	printf("%i\n",ans);
	return 0;
}