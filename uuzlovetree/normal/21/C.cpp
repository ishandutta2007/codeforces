#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n;
int a[maxn];
int pre[maxn],suf[maxn];
map<int,int> ms;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]+a[i];
	for(int i=n;i>=3;--i)ms[suf[i]]++;
	ll ans=0;
	for(int i=2;i<=n-1;++i)
	{
		if(pre[i-1]*2==suf[i])
		{
			ans+=1ll*ms[pre[i-1]]; 
		}
		ms[suf[i+1]]--;
	}
	printf("%I64d\n",ans);
	return 0; 
}