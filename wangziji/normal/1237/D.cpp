#include <iostream>
#include <queue>
using namespace std;
int a[400005],ans[400005];
priority_queue <pair<int,int> > q;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=n+1;i<=n*4;i++)
		a[i]=a[(i-1)%n+1],ans[i]=ans[(i-1)%n+1]=123456789;
	for(int i=1;i<=n*4;i++)
	{
		while(!q.empty()&&q.top().first>a[i]*2)
		{
			ans[q.top().second]=i;
			q.pop();
		}
		q.push(make_pair(a[i],i));
	}
	for(int i=n*4-1;i>=0;i--)
		ans[i]=min(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++)
	{
		if(ans[i]-i>2000000)
			cout << -1 << " ";
		else
			cout << ans[i]-i << " ";
	}
	return 0;
}