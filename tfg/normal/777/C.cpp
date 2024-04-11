#include <iostream>
#include <cstdio>
#include <vector>

const int ms=100100;

std::vector<int> a[ms], b[ms], c[ms], d[ms];

int ans[ms];


int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		a[i].push_back(0);
		b[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			int temp;
			scanf("%i", &temp);
			a[i].push_back(temp);
			b[i].push_back(0);
		}
	}
	b[0]=b[1];
	a[0]=b[1];
	for(int i=0;i<=n;i++)
		c[i]=b[0];
	for(int i=0;i<=n;i++)
		d[i]=b[0];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]<a[i-1][j])
				b[i][j]=1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		int on=1;
		for(int i=1;i<=n;i++)
		{
			d[i][j]=ms;
			if(b[i][j])
			{
				for(;on<i;on++)
					d[on][j]=i-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=0;
		for(int j=1;j<=m;j++)
			ans[i]=std::max(ans[i], d[i][j]);
		//std::cout << ans[i] << '\n';
	}

	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]+=b[i][j-1];
			c[i][j]=c[i-1][j]+b[i][j];
		}
	}*/

	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			std::cout << d[i][j] << ' ';
		std::cout << '\n';
	}*/
	int q;
	std::cin >> q;
	while(q--)
	{
		int l, r;
		scanf("%i %i",&l,&r);
		if(ans[l]>=r)
			printf("Yes\n");
		else
			printf("No\n");
	}
}