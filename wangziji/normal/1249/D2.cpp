#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int cf[200005];
struct node
{
	int l,r,id;
}a[200005];
inline bool cmp(node x,node y)
{
	return x.l<y.l;
}
priority_queue <pair<int,int> > q;
int ans[200005],cnt;
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].l >> a[i].r;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	while(!q.empty())
		q.pop();
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i-1].l+1;j<=a[i].l;j++)
			cf[j]+=cf[j-1];
		++cf[a[i].l];
		--cf[a[i].r+1];
		q.push(make_pair(a[i].r,a[i].id));
		while(cf[a[i].l]>k)
		{
			--cf[a[i].l];
			++cf[q.top().first+1];
			ans[++cnt]=q.top().second;
			q.pop();
		}
	}
	cout << cnt << endl;
	for(int i=1;i<=cnt;i++)
		cout << ans[i] << " ";
	return 0;
}