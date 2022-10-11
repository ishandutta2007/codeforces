#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

typedef std::pair<int, int> ii;
typedef long long int ll;

const int ms=100100;

int n, m;
int a[ms];

std::vector<int> edges[ms];
std::priority_queue<ii> hp;

int par[ms];
ll size[ms];
ll minimum[ms];

int get_par(int x)
{
	if(par[x]==x)
		return x;
	return par[x]=get_par(par[x]);
}

ll ans=0;

void make_union(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return;
	minimum[a]=std::min(minimum[a], minimum[b]);
	//std::cout << "making union of " << a << " and " << b << '\n';
	ans+=size[a]*size[b]*minimum[a]*2;
	size[a]+=size[b];
	par[b]=a;
}

int main()
{
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		scanf("%i",a+i);
		hp.push(ii(a[i], i));
		minimum[i]=a[i];
		par[i]=i;
		size[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int t1, t2;
		scanf("%i %i",&t1,&t2);
		edges[t1].push_back(t2);
		edges[t2].push_back(t1);
	}
	while(!hp.empty())
	{
		int on=hp.top().second;
		hp.pop();
		//std::cout << "got " << on << " from the heap.\n";
		for(int i=0;i<edges[on].size();i++)
		{
			if(a[edges[on][i]]>=a[on])
				make_union(on,edges[on][i]);
		}
	}
	printf("%.10lf\n",(double)ans/(double)((double)(n)*(double)(n-1)));
}