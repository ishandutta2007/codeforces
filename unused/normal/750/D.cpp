#include <bits/stdc++.h>
using namespace std;

int dat[33];
unsigned char v1[300][300], v2[300][300];
bool z[300][300];
unsigned char nxt[256];
pair<int, int> dr[256];

int main()
{
	for (int i = 2; i <= 64; i <<= 1)
		nxt[i] = (i << 1) | (i >> 1);
	nxt[1] = 128 | 2;
	nxt[128] = 64 | 1;

	dr[1] = { 0, -1 };
	dr[2] = { 1, -1 };
	dr[4] = { 1, 0 };
	dr[8] = { 1, 1 };
	dr[16] = { 0, 1 };
	dr[32] = { -1, 1 };
	dr[64] = { -1, 0 };
	dr[128] = { -1, -1 };

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	auto vv1 = v1, vv2 = v2;
	vv1[150][150] = 1;

	for (int i = 0; i < n; i++)
	{
		memset(vv2, 0, sizeof(v1));
		for (int x = 0; x < 300; x++)
		{
			for (int y = 0; y < 300; y++)
			{
				for (int flag = 1; flag <= 128; flag *= 2)
				{
					if (vv1[x][y] & flag)
					{
						for (int k = 1; k <= dat[i]; k++)
						{
							z[x + dr[flag].first * k][y + dr[flag].second * k] = true;
						}
						vv2[x + dr[flag].first * dat[i]][y + dr[flag].second * dat[i]] |= nxt[flag];
					}
				}
			}
		}

		swap(vv1, vv2);
	}

	int ans = 0;
	for (int x = 0; x < 300; x++) for (int y = 0; y < 300; y++) ans += z[x][y];
	printf("%d", ans);
}