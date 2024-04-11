#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int x[N],y[N],n,px,py;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(n&1)
	{
		puts("NO");
		return 0;
	}
	for(int i=2;i<=n/2;i++)
	{
		if(x[1]+x[n/2+1]!=x[i]+x[n/2+i]||y[1]+y[n/2+1]!=y[i]+y[n/2+i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}