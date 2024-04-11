#include <iostream>
#include <cstdio>
using namespace std;
int n, x, y;
long long t[2][2];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		x /= 2, y /= 2;
		x &= 1, y &= 1;
		t[x][y]++;
	}
	long long ans = 0;
	for (int xx1 = 0; xx1 <= 1; xx1++)
	{
	for (int yy1 = 0; yy1 <= 1; yy1++)
	{
	for (int xx2 = 0; xx2 <= 1; xx2++)
	{
	for (int yy2 = 0; yy2 <= 1; yy2++)
	{
	for (int xx3 = 0; xx3 <= 1; xx3++)
	{
	for (int yy3 = 0; yy3 <= 1; yy3++)
	{
		int cnt = 0;
		if((xx1 - xx2 + 2) % 2 != 0 || 0 != (yy1 - yy2 + 2) % 2) cnt++;
		if((xx2 - xx3 + 2) % 2 != 0 || 0 != (yy2 - yy3 + 2) % 2) cnt++;
		if((xx1 - xx3 + 2) % 2 != 0 || 0 != (yy1 - yy3 + 2) % 2) cnt++;
		if(cnt % 2 == 1) continue;
		int bef = ans;
		if(cnt % 2 == 0) ans += t[xx1][yy1] * t[xx2][yy2] * t[xx3][yy3];
		if(ans == bef) continue;
//		printf("%d %d %d %d %d %d\n", xx1, yy1, xx2, yy2, xx3, yy3);
	}
	}
	}
	}
	}
	}
	long long ans2 = 0, ans3 = 0;
	for (int xx1 = 0; xx1 <= 1; xx1++)
	{
	for (int yy1 = 0; yy1 <= 1; yy1++)
	{
	for (int xx2 = 0; xx2 <= 1; xx2++)
	{
	for (int yy2 = 0; yy2 <= 1; yy2++)
	{
		ans2 += t[xx1][yy1] * t[xx2][yy2];
	}
	}
	}
	}
	for (int xx1 = 0; xx1 <= 1; xx1++)
	{
	for (int yy1 = 0; yy1 <= 1; yy1++)
	{
		ans3 += t[xx1][yy1];
	}
	}
//	printf("%lld %lld %lld\n", ans, ans2, ans3);
	ans = (ans - ans2 * 3 + 2 * ans3) / 6; 
	printf("%lld", ans);
	return 0;
}