#include <bits/stdc++.h>
#define Maxn 200007
#define inf 1000000007
using namespace std;
int n,m,c,ans;
long long anss;
long long p[Maxn];
int a[Maxn],b[Maxn];
multiset<long long> s[4][4];
multiset<long long>::iterator it;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) if (a[i]>b[i]) swap(a[i],b[i]);
	for (int i=1;i<=n;i++) s[a[i]][b[i]].insert(p[i]),s[b[i]][a[i]].insert(p[i]);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d",&c);
		anss=inf;
		for (int i=1;i<=3;i++)
		{
			it=s[i][c].begin();
			if (s[i][c].size()>=1&&(*it)<anss)
			{
				anss=(*it);
				ans=i;
			}
		}
		if (anss==inf) printf("%d ",-1); else
		{
			printf("%I64d ",anss);
			it=s[ans][c].begin(),s[ans][c].erase(it);
			it=s[c][ans].begin(),s[c][ans].erase(it);
		}
	}
	printf("\n");
	return 0;
}