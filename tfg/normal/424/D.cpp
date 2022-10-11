#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <utility>

typedef std::pair<int, int> iii;

const int ms = 330;

int n, m, t;
int h[ms][ms];
int hor[ms][ms][3], vert[ms][ms][3];
int cost[3];
// 0 == flat, 1 == ascent, 2 == descent

int getType(int h0, int h1)
{
	if(h0 == h1)
		return 0;
	else if(h0 < h1)
		return 1;
	else
		return 2;
}

int getVert(int col, int r0, int r1, bool invert)
{
	int freq[3];
	for(int i = 0; i < 3; i++)
		freq[i] = vert[r1][col][i] - vert[r0][col][i];
	if(invert)
		std::swap(freq[1], freq[2]);
	int ans = 0;
	for(int i = 0; i < 3; i++)
		ans += freq[i] * cost[i];
	return ans;
}

int getHor(int row, int c0, int c1, bool invert)
{
	int freq[3];
	for(int i = 0; i < 3; i++)
		freq[i] = hor[row][c1][i] - hor[row][c0][i];
	if(invert)
		std::swap(freq[1], freq[2]);
	int ans = 0;
	for(int i = 0; i < 3; i++)
		ans += freq[i] * cost[i];
	return ans;
}
int hmm[ms];


int main()
{
	std::cin >> n >> m >> t >> cost[0] >> cost[1] >> cost[2];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			std::cin >> h[i][j];
			vert[i][j][getType(h[i][j], h[i - 1][j])]++;
			hor[i][j][getType(h[i][j - 1], h[i][j])]++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				vert[i][j][k] += vert[i - 1][j][k];
				hor[i][j][k] += hor[i][j - 1][k];
			}
		}
	}
	int r0, r1, c0, c1, ans = 2e9;
	for(int i = 1; i <= n; i++)
	{
		for(int ii = i + 2; ii <= n; ii++)
		{
			std::set<iii> nums;
			for(int j = 3; j <= m; j++)
			{
				int cur = getHor(i, 1, j, false) + getHor(ii, 1, j, true) + getVert(j, i, ii, true);
				nums.insert(iii(cur, j));
				hmm[j] = cur;
			}
			int offset = 0;
			for(int j = 1; j + 2 <= m; j++)
			{
				offset = getHor(i, 1, j, false) + getHor(ii, 1, j, true) - getVert(j, i, ii, false);
				auto it = nums.lower_bound(iii(t + offset, -1));
				if(it != nums.end())
				{
					int cur = it->first - offset;
					if(abs(cur - t) < ans)
					{
						r0 = i;
						r1 = ii;
						c0 = j;
						c1 = it->second;
						ans = abs(cur - t);
					}
				}
				if(it != nums.begin())
				{
					it--;
					int cur = it->first - offset;
					if(abs(cur - t) < ans)
					{
						r0 = i;
						r1 = ii;
						c0 = j;
						c1 = it->second;
						ans = abs(cur - t);
					}
				}
				nums.erase(iii(hmm[j + 2], j + 2));
			}
		}
	}
	std::cout << r0 << ' ' << c0 << ' ' << r1 << ' ' << c1 << '\n';
}