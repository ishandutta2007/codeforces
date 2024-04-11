#include <iostream>

int par[1010];
int size[1010];

int get_par(int x)
{
	if(par[x]==x) return x;
	return par[x]=get_par(par[x]);
}

void make_union(int a, int b)
{
	a=get_par(a);
	b=get_par(b);
	if(a==b) return;
	size[a]+=size[b];
	par[b]=a;
}



int get_num(int a)
{
	a=get_par(a);
	if(size[a]%2==0) return size[a]/2;
	return size[a];
}


int n;

long long int gcd(long long int a, long long int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

long long int lcm(long long int a, long long int b)
{
	long long int ans=a*b;
	return ans/gcd(a,b);
}

int a[1010];

bool visit[1010];

bool cycle(int x, int start)
{
	if(x==start) return true;
	if(visit[x]) return false;
	if(a[x]==x) return false;
	visit[x]=true;
	bool ans=cycle(a[x],start);
	visit[x]=false;
	return ans;
}

int main()
{
	std::cin >> n;
	for(int i=0;i<n;i++)
	{
		size[i]=1;
		par[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		std::cin >> a[i];
		a[i]--;
		make_union(a[i],i);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==i) continue;
		if(!cycle(a[i],i))
		{
			std::cout << "-1\n";
			return 0;
		}
	}
	long long int ans=1;
	for(int i=0;i<n;i++)
	{
		ans=lcm(ans,get_num(i));
	}
	std::cout << ans << '\n';
}