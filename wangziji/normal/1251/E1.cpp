#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
struct node
{
	int x,y;
}a[200005];
inline int cmp(node x,node y)
{
	return x.x>y.x;
}
int qzh[200005];
priority_queue <int,vector<int>,greater<int> > q;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		while(!q.empty()) q.pop();
		for(int i=0;i<=n;i++) qzh[i]=0;
		for(int i=1;i<=n;i++)
		{ 
			cin >> a[i].x >> a[i].y;
			++qzh[a[i].x];
		}
		for(int i=1;i<=n;i++) qzh[i]+=qzh[i-1];
		int now=0,ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(i!=n&&a[i].x==a[i+1].x)
			{
				q.push(a[i].y);
				continue;
			}
			q.push(a[i].y);
			int t=a[i].x-qzh[a[i].x-1];
			while(t>now)
			{
				ans+=q.top();
				q.pop();
				++now;
			}
		}
		cout << ans << endl;
	}
	return 0;
}