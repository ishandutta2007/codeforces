#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
int a[N],n,Q,mx,cnt;
pair<int ,int >ans[N];
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	int l=1,r=n;
	while(a[l]!=mx)
	{
		int x=a[l],y=a[l+1];l+=2;ans[++cnt]=make_pair(x,y);
		if(x>y)a[--l]=x,a[++r]=y;else a[--l]=y,a[++r]=x;
	}
	while(Q--)
	{
		ll x;
		scanf("%lld",&x);
		if(x<=cnt)printf("%d %d\n",ans[x].first,ans[x].second);
		else x-=cnt,x=(x-1)%(n-1)+1,printf("%d %d\n",mx,a[l+x]);
	}
}