#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int a[1000005],cnt;
queue <int> q1,q2;
struct node
{
	int a,b,c;
};
node ans[1000005];
signed main() {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		a[u]-=w,a[v]+=w;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0) q1.push(i),a[i]=-a[i];
		else if(a[i]>0) q2.push(i);
	}
	while(!q1.empty())
	{
		int x=q1.front();
		q1.pop();
		//cout << a[x] << " " << a[q2.front()] << endl;
		while(a[q2.front()]<a[x])
		{
			a[x]-=a[q2.front()];
			if(a[q2.front()]) ans[++cnt]={x,q2.front(),a[q2.front()]};
			q2.pop();
		}
		a[q2.front()]-=a[x];
		if(a[x]) ans[++cnt]={x,q2.front(),a[x]};
		a[x]=0;
	}
	cout << cnt << endl;
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i].c)
		{
			cout << ans[i].a << " " << ans[i].b << " " << ans[i].c;
			puts("");
		}
	}
	return 0;
}