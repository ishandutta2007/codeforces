#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,k;
int a[maxn];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int ans=n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	k=n-k;
	for(int i=1;i<n;++i)q.push(a[i+1]-a[i]-1);
	while(k--)
	{
		int t=q.top();
		q.pop();
		ans+=t;
	}
	printf("%d\n",ans);
	return 0;
}