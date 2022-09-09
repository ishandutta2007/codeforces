#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=200050;
priority_queue<pair<int,int> > pq;
int c,sol[N];
pair<int,int> a[N];
int main()
{
	int n,m,i,d;
	scanf("%i %i %i",&n,&m,&d);
	for(i=1;i<=n;i++) scanf("%i",&a[i].first),a[i].second=i;
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(pq.empty() || a[i].first+pq.top().first<=d)
		{
			sol[a[i].second]=++c;
			pq.push(mp(-a[i].first,c));
		}
		else
		{
			pair<int,int> tmp=pq.top();pq.pop();
			sol[a[i].second]=tmp.second;
			tmp.first=-a[i].first;
			pq.push(tmp);
		}
	}
	printf("%i\n",c);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);printf("\n");
	return 0;
}