#include<bits/stdc++.h>
using namespace std;
const int N=300005;
long long a[N],vis[N];
pair<long long,int>b[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) continue;
		b[i]=make_pair(a[i]-a[i-1],i);
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	for(int i=1;i<k;i++)
		vis[b[i].second]=1;
	long long ans=0;
	int last=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			if(!vis[i-1])
				ans+=a[i-1]-a[last];
			last=i;
		}
	}
	if(!vis[n])
		ans+=a[n]-a[last];
	cout<<ans<<endl;
	return 0;
}