#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
struct node
{
	int a,b;
}a[100005];
inline int cnt(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=(x&1);
		x>>=1;
	}
	return rtn;
}
inline bool cmp(node x,node y)
{
	return cnt(x.a)>cnt(y.a)||cnt(x.a)==cnt(y.a)&&x.a>y.a;
}
int v[10005],n;
inline void dfs(int x)
{
	v[x]=1;
	for(int i=x+1;i<=n;i++)
	{
		if((a[x].a&a[i].a)==a[i].a)
		{
			if(!v[i])
			{
				v[i]=1;
				dfs(i);
			}
		}
	}
}
signed main() {
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i].a;
	for(int i=1;i<=n;i++)
		cin >> a[i].b;
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].a==a[i+1].a)
		{
			dfs(i);
			int t=0;
			for(int j=1;j<=n;j++)
				t+=v[j]*a[j].b;
			ans=max(ans,t);
		}
	}
	cout << ans;
	return 0;
}