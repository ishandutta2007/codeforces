#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,a[Maxn],val[30],ans,sum;
void work(int x)
{
	if(!x) return ;
	int hb=log2(x);
	if(!val[hb]) val[hb]=x;
	else
		work(x^=val[hb]);
}
int main()
{
//	freopen("G.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum^=a[i];
	if(!sum)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		work(a[i]);
	for(int i=0;i<=29;i++)
		if(val[i]) ans++;
	printf("%d",ans);
	return 0;
}