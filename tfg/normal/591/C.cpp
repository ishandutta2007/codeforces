#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <bitset>

const int ms = 500001;

int a[ms];
int par[ms];
int size[ms];

int get_par(int x)
{
	if(par[x] == x)
		return x;
	else
		return par[x] = get_par(par[x]);
}

void make_union(int a, int b)
{
	a = get_par(a);
	b = get_par(b);
	if(a == b)
		return;
	size[a] += size[b];
	par[b] = a;
}

int main()
{
	int n;
	srand(time(NULL));
	while(std::cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%i", a + i);
			par[i] = i;
			size[i] = 1;
		}
		for(int i = 1; i < n; i++)
		{
			if(a[i] == a[i - 1])
				make_union(i, i - 1);
		}
		int ans = 0;
		for(int i = 1; i + 1 < n; i++)
		{
			if(size[get_par(i)] > 1)
				continue;
			int l = i;
			int r = i;
			while(r + 1 < n && size[get_par(r)] == 1)
				r++;
			r--;
			i = r + 1;
			int cur = 0;
			//std::cout << "found (" << l << ", " << r << ")\n";
			while(l <= r)
			{
				a[l] = a[l - 1];
				a[r] = a[r + 1];
				cur++;
				l++;
				r--;
			}
			ans = std::max(cur, ans);
			
		}
		std::cout << ans << '\n';
		for(int i = 0; i < n; i++)
		{
			if(i)
				printf(" ");
			printf("%i", a[i]);
		}
		std::cout << '\n';
	}
}