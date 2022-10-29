#include <iostream>
#include <queue>
#define int long long
using namespace std;
priority_queue <int> q;
int n,m,k;
struct node
{
	int l,r;
}a[200005];
inline bool pd(int x)
{
	while(!q.empty()) q.pop();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].r>=x)
			q.push(a[i].l);
		ans+=a[i].l;
	}
	if(q.size()<m)
		return 0;
	for(int i=1;i<=m;i++)
	{
		if(q.top()<x) ans-=q.top(),ans+=x;
		q.pop();
	}
	if(ans>k)
		return 0;
	return 1;
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i].l >> a[i].r;
		int l=0,r=1000000000,ans=0;m=(n+1)/2;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(pd(mid)) ans=max(ans,mid),l=mid+1;
			else r=mid-1;
		}
		cout << ans << endl;
	}
	return 0;
}