#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 100005
int a[N*2];
int ans1[N];
int ans2[N];
signed main()
{
	int n,q;
	cin>>n>>q;
	int maxn=0;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	int tu=0;
	while(a[l]!=maxn)
	{
		tu++;
		ans1[tu]=a[l],ans2[tu]=a[l+1];
		a[++r]=min(a[l],a[l+1]);
		a[l+1]=max(a[l],a[l+1]);
		l++;
	}
	for(int i=1;i<=q;i++)
	{
		int x=read();
		if(x<=tu)
		{
			cout<<ans1[x]<<" "<<ans2[x]<<endl;
			continue;
		}
		x-=tu;
		x%=(n-1);
		if(x==0) x=n-1;
		cout<<a[l]<<" "<<a[l+x]<<endl;
	}
	return 0;
}