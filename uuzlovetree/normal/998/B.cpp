#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
#define maxn 105
int n,B;
int a[maxn];
int s[maxn];
int p[maxn],cnt;
int main()
{
	scanf("%d%d",&n,&B);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)s[i]=s[i-1]+1;
		else s[i]=s[i-1]-1;
	}
	for(int i=1;i<n;++i)if(!s[i])p[++cnt]=abs(a[i]-a[i+1]);
	sort(p+1,p+cnt+1);
	int ans=0;
	for(int i=1;i<=cnt;++i)
	{
		if(p[i]<=B)ans++,B-=p[i];
		else break;
	}
	cout<<ans<<endl;
	return 0;
}