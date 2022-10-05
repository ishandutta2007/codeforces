#include <bits/stdc++.h>
#define y1 yyy
using namespace std;

const int Maxn = 200005;
int n, x1[Maxn], y1[Maxn], x2[Maxn], y2[Maxn];
pair <int, int> mini_x, maxi_x, mini_y, maxi_y;
int main()
{
	scanf("%d", &n);
	x1[0] = y1[0] = -0x3f3f3f3f;
	x2[n + 1] = y2[n + 1] = 0x3f3f3f3f;
	mini_x = mini_y = make_pair(n + 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x2[i] < x2[mini_x.first]) mini_x.second = mini_x.first, mini_x.first = i;
		else if (x2[i] < x2[mini_x.second]) mini_x.second = i;
		if (x1[i] > x1[maxi_x.first]) maxi_x.second = maxi_x.first, maxi_x.first = i;
		else if (x1[i] > x1[maxi_x.second]) maxi_x.second = i;
		if (y2[i] < y2[mini_y.first]) mini_y.second = mini_y.first, mini_y.first = i;
		else if (y2[i] < y2[mini_y.second]) mini_y.second = i;
		if (y1[i] > y1[maxi_y.first]) maxi_y.second = maxi_y.first, maxi_y.first = i;
		else if (y1[i] > y1[maxi_y.second]) maxi_y.second = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int Mini_x, Maxi_x, Mini_y, Maxi_y;
		Mini_x = mini_x.first == i ? x2[mini_x.second] : x2[mini_x.first];
		Maxi_x = maxi_x.first == i ? x1[maxi_x.second] : x1[maxi_x.first];
		Mini_y = mini_y.first == i ? y2[mini_y.second] : y2[mini_y.first];
		Maxi_y = maxi_y.first == i ? y1[maxi_y.second] : y1[maxi_y.first];
		if (Mini_x >= Maxi_x && Mini_y >= Maxi_y)
		{
			printf("%d %d", Mini_x, Mini_y);
			return 0;
		}
	}
	return 0;
}