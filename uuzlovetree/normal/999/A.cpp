#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
using namespace std;
int n,k;
int a[maxn];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=k)a[i]=0;
		else break;
	}
	for(int i=n;i;--i)
	{
		if(a[i]<=k)a[i]=0;
		else break;
	}
	int ans=0;
	for(int i=1;i<=n;++i)if(!a[i])ans++;
	cout<<ans<<endl;
	return 0;
}