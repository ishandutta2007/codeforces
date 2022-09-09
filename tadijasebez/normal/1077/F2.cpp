#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
const int N=5050;
deque<pair<ll,int> > q[N];
int a[N];
int main()
{
	int n,k,x,i,j;
	scanf("%i %i %i",&n,&k,&x);
	q[0].push_front(mp(0,0));
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		for(j=x;j>=1;j--)
		{
			while(q[j-1].size() && q[j-1].front().second<i-k) q[j-1].pop_front();
			if(q[j-1].size())
			{
				ll tmp=q[j-1].front().first+a[i];
				while(q[j].size() && q[j].back().first<=tmp) q[j].pop_back();
				q[j].push_back(mp(tmp,i));
			}
		}
	}
	while(q[x].size() && q[x].front().second<=n-k) q[x].pop_front();
	if(q[x].empty()) printf("-1\n");
	else printf("%lld\n",q[x].front().first);
	return 0;
}