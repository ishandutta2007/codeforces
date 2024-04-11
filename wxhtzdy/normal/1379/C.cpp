#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int nax=1000*107;

int tab[nax][2];

int v[nax];

ll pref[nax];

void test()
{
	int n,m;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &tab[i][0], &tab[i][1]);
		v[i]=tab[i][0];
	}
	sort(v+1, v+m+1);
	reverse(v+1, v+m+1);
	ll ans=0;
	for (int i=1; i<=m; i++) 
	{
		if (i<=n) ans+=v[i];
		pref[i]=pref[i-1]+v[i];
	}
	for (int i=1; i<=m; i++)
	{
		int bot=1, top=m, j=0;
		while (bot<=top)
		{
			int mid=(bot+top)/2;
			if(v[mid]>=tab[i][1]) j=mid,bot=mid+1;
			else top=mid-1;
		}
		int ima=n-j-1;
		if (ima<0) continue;
		ll sum=pref[j]+tab[i][0];
		if (tab[i][0]>=tab[i][1])
		{
			ima++;
			sum-=tab[i][0];
		}
		ans=max(ans, tab[i][1]*1LL*ima+sum);
	}
	printf("%lld\n", ans);
}
	
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		test();
	return 0;
}