#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
int n;
ll h,a[maxn],b[maxn];
bool check(int k)
{
	memset(b,0,sizeof(b));
	for(int i=1;i<=k;++i)b[i]=a[i];
	sort(b+1,b+k+1);
	ll res=0;
	for(int i=k;i>=1;i-=2)res+=b[i];
	return res<=h;
}
int main()
{
	scanf("%d%I64d",&n,&h);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int ans=n;ans>=1;--ans)
	{
		if(check(ans))
		{
			printf("%d\n",ans);
			break;
		}
	}
	return 0;
}