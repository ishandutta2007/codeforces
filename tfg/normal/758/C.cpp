#include <iostream>

typedef long long int ll;
ll n, m, k, x, y;

ll seat[110][110];
ll one[110][110];

int main()
{
	std::cin >> n >> m >> k >> x >> y;
	ll num=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			one[i][j]++;
			num++;
		}
	}
	for(int i=n-1;i>1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			one[i][j]++;
			num++;
		}
	}

	ll times=k/num;
	ll rest=k%num;
	//std::cout << "num is " << num << '\n';
	//std::cout << "times is " << times << '\n';
	//std::cout << "rest is " << rest << '\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			seat[i][j]=times*one[i][j];
		}
	}

	for(int i=1;i<=n && rest;i++)
	{
		for(int j=1;j<=m && rest;j++)
		{
			seat[i][j]++;
			rest--;
		}
	}
	for(int i=n-1;i>1 && rest;i--)
	{
		for(int j=1;j<=m && rest;j++)
		{
			seat[i][j]++;
			rest--;
		}
	}

	ll max=0;
	ll min=k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//std::cout << seat[i][j] << ' ';
			min=std::min(min, seat[i][j]);
			max=std::max(max, seat[i][j]);
		}
		//std::cout << '\n';
	}

	std::cout << max << ' ' << min << ' ' << seat[x][y] << '\n';
}