#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define mp make_pair

const int N = (int)2e5 + 100;
const int A = 26;
char hay[N], needle[N];
int letter_pos[A];
int z[2 * N];

char merged[2 * N];
bool good_position[A][A][N];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	scanf(" %s %s", hay, needle);

	memset(letter_pos, -1, sizeof(letter_pos));
	for (int i = m - 1; i >= 0; i--)
		letter_pos[needle[i] - 'a'] = i;

	for (int i = 0; i < m; i++)
		merged[i] = needle[i];
	for (int i = 0; i < n; i++)
		merged[i + m] = hay[i];

	for (char a = 'a'; a <= 'z'; a++)
		for (char b = a; b <= 'z'; b++)
		{
			int id_a = a - 'a';
			int id_b = b - 'a';
			int l = -1, r = 0;
			for (int i = 1; i < n + m; i++)
			{
				z[i] = 0;
				if (i < r)
					z[i] = min(z[i - l], r - i);
				while (i + z[i] < n + m)
				{
					char c1 = merged[z[i]];
					char c2 = merged[i + z[i]];
					if (z[i] < m)
						c1 = (c1 == a ? a : (c1 == b ? b : '#'));
					else
						c1 = (c1 == a ? b : (c1 == b ? a : '#'));

					if (i + z[i] < m)
						c2 = (c2 == a ? a : (c2 == b ? b : '#'));
					else
						c2 = (c2 == a ? b : (c2 == b ? a : '#'));

					if (c1 == c2)
						z[i]++;
					else
						break;
				}
				if (i + z[i] > r)
				{
					l = i;
					r = i + z[i];
				}
				if (z[i] >= m && i >= m)
				{
					good_position[id_a][id_b][i - m] = 1;
				}
			}
		}

	vector <int> answer;
	for (int i = 0; i <= n - m; i++)
	{
		bool ok = true;
		for (int a = 0; a < A; a++)
		{
			int pos = letter_pos[a];
			if (pos == -1) continue;
			int b = hay[i + pos] - 'a';
			if (!good_position[min(a, b)][max(a, b)][i])
			{
				ok = false;
				break;
			}
		}
		if (ok)
			answer.push_back(i + 1);
	}
	printf("%d\n", (int)answer.size());
	for (int p : answer)
		printf("%d ", p);

	return 0;
}