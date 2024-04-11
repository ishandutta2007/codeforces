#include <iostream>

const int ms=100100;

typedef long long int ll;

int n, m, k;

int par[ms];
int size[ms];
bool owned[ms];
bool visit[ms];

int get_par(int x)
{
	if(par[x]==x)
		return x;
	return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return;
	size[a]+=size[b];
	owned[a]=owned[a]||owned[b];
	par[b]=a;
}

void init()
{
	std::cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		size[i]=1;
	}
	for(int i=1;i<=k;i++)
	{
		std::cin >> par[n+i];
		//std::cout << "got " << par[n+i] << '\n';
		owned[par[n+i]]=true;
	}
	for(int i=1;i<=m;i++)
	{
		int t1, t2;
		std::cin >> t1 >> t2;
		make_union(t1, t2);
	}
}

int main()
{
	init();
	int v_max=0, v_where;
	for(int i=1;i<=k;i++)
	{
		int on=get_par(i+n);
		//std::cout << "city " << i << " has rep " << on << ", size " << size[on] << " and " << (owned[on]?"is owned":"is not owned") << '\n';
		if(size[on]>v_max)
		{
			v_max=size[on];
			v_where=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int on=get_par(i);
		if(!owned[on])
			make_union(on, n+v_where);
	}
	ll total=0;
	for(int i=1;i<=n;i++)
	{
		int on=get_par(i);
		if(!visit[on])
		{
			visit[on]=true;
			//std::cout << "on rep " << on << ", size " << size[on] << '\n';
			ll cur_total=size[on];
			cur_total=((cur_total-1)*cur_total)/2;
			//std::cout << "added " << cur_total << " edges\n";
			total+=cur_total;
		}
	}
	std::cout << total-m << '\n';
}