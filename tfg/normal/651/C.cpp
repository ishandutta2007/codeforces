#include <cstdio>
#include <iostream>
#include <map>
#include <utility>

typedef std::pair<int, int> ii;

std::map<ii, int> points;
std::map<int, int> row, col;

int n;

int main()
{
	std::cin >> n;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		int x, y;
		scanf("%i %i",&x,&y);
		ans+=row[y]+col[x]-points[ii(x, y)];
		row[y]++;
		col[x]++;
		points[ii(x, y)]++;
	}
	std::cout << ans << '\n';
}