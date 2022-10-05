#include <bits/stdc++.h>
using namespace std;
int n;
const int Maxn=100005;
double a[Maxn],b[Maxn],ans[Maxn];
long long tot;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		ans[i]=b[i]=ceil(a[i]);
		tot+=(int)b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(!tot) break;
		if(a[i]!=(int)a[i]) ans[i]=b[i]-1,tot--;
	}
	for(int i=1;i<=n;i++)
	{
		if(abs(ans[i])<=0.00001) ans[i]=0.00001;
		printf("%.0f\n",ans[i]);
	}
	return 0;
}