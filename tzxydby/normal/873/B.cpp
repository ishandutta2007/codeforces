#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
pair<int,int>s[N];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
		if(!a[i])
			a[i]--;
		s[i]=make_pair(s[i-1].first+a[i],i);	
	}
	sort(s,s+n+1);
	for(int i=0;i<=n;i++)
	{
		int j;
		for(j=i;s[j].first==s[j+1].first&&j<n;j++);
		ans=max(ans,s[j].second-s[i].second);		
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}