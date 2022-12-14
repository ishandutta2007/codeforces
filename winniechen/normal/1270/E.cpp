#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,cnt,ans[N],a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y); a[i] = x, b[i] = y;
		// if((x+y)&1)ans[++cnt] = i;
	}
	while(cnt == 0 || cnt == n)
	{
		cnt = 0;
		for(int i=1,x,y;i<=n;i++)
		{
			x = a[i] , y = b[i];
			if((a[i]+b[i])&1)ans[++cnt] = i;
			a[i] = (x+y)>>1, b[i] = (x-y)>>1;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);puts("");
}