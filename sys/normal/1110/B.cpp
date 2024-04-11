#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,b[100005];
priority_queue <int,vector<int>,greater<int> > Pr;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+1+n);
	for(int i=2;i<=n;i++)
		Pr.push(b[i]-b[i-1]);
	for(int i=1;i<=n-k;i++)
	{
		ans+=Pr.top();
		Pr.pop();
	}
	printf("%d",ans+k);
	return 0;
}