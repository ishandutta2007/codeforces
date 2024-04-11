#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

const int ms=100100;

int par[ms], ant[ms];

int get_par(int x)
{
	if(x==-1)
		return -1;
	if(x==par[x])
		return x;
	else
		return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	if(a==-1 || b==-1)
		return;
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return;
	par[b]=a;
}

bool try_sin(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return true;
	else if(get_par(ant[a])==b)
		return false;
	else
	{
		int c=get_par(ant[a]), d=get_par(ant[b]);
		make_union(c, d);
		int e=std::max(c, d);
		if(e!=-1)
			ant[get_par(e)]=get_par(a);
		ant[a]=get_par(e);
		par[b]=a;
		return true;
	}
}

bool try_ant(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b)
		return false;
	else if(get_par(ant[a])==b)
		return true;
	else
	{
		int c=get_par(ant[a]), d=get_par(ant[b]);
		make_union(c, b);
		make_union(a, d);
		ant[get_par(a)]=get_par(b);
		ant[get_par(b)]=get_par(a);
		return true;
	}
}

std::map<std::string, int> hmm;

int read_str()
{
	std::string str;
	std::cin >> str;
	int ans=hmm[str];
	if(ans==0)
	{
		ans=hmm.size();
		hmm[str]=ans;
	}
	//std::cout << "reading " << str << ", num is " << ans << '\n';
	return ans;
}

int main()
{std::ios_base::sync_with_stdio(false);std::cin.tie(0);
	int n, m, q;
	std::cin >> n >> m >> q;
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		ant[i]=-1;
	}
	for(int i=0;i<n;i++)
		read_str();
	for(int i=0;i<m;i++)
	{
		int a;
		//scanf("%i",&a);
		std::cin >> a;
		int u=read_str();
		int v=read_str();
		bool ans;
		if(a==1)
			ans=try_sin(u, v);
		else
			ans=try_ant(u, v);
		if(ans)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
	while(q--)
	{
		int u=read_str();
		int v=read_str();
		u=get_par(u);
		v=get_par(v);
		if(ant[u]==v)
			std::cout << "2\n";
		else if(u==v)
			std::cout << "1\n";
		else
			std::cout << "3\n";
	}
}