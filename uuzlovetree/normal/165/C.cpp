#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int n,k;
char s[maxn];
int a[maxn],cnt;
ll ans;
int main()
{
	scanf("%d",&k);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)if(s[i]=='1')a[++cnt]=i;
	if(!k)
	{
		int last=0;
		s[n+1]='1';
		for(int i=1;i<=n+1;++i)if(s[i]=='1')
		{
			ll t=i-last-1;
			ans+=t*(t+1)/2;
			last=i;
		}
		cout<<ans<<endl;
		return 0;
	}
	a[++cnt]=n+1;
	for(int i=1;i<=cnt;++i)if(i+k<=cnt)
	{
		int L=a[i-1]+1,l=a[i];
		int r=a[i+k-1],R=a[i+k]-1;
		ans+=1ll*(l-L+1)*(R-r+1);
	}
	cout<<ans<<endl;
	return 0;
}