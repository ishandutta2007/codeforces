#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 10;
vector <int> ans;
int v[N], p[N], d[N];
bool in[N];
int n;

void go(int id)
{
	in[id] = false;
	ans.push_back(id);
	int delta = v[id];
	for (int i = id + 1; i < n; i++)
	{
		if (!in[i])
			continue;
		if (delta <= 0)
			break;
		p[i] = max(-1, p[i] - delta);
		delta--;
	}
	while (1)
	{
		bool change = false;
		for (int i = id + 1; i < n; i++)
		{
			if (p[i] < 0 && in[i])
			{
				in[i] = false;
				change = true;
				for (int s = i + 1; s < n; s++)
				{
					p[s] = max(-1, p[s] - d[i]);
				}
			}
		}
		if (!change)
			break;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &v[i], &d[i], &p[i]);
	}
	fill(in, in + n, true);
	for (int i = 0; i < n; i++)
	{
		if (p[i] >= 0)
			go(i);
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans)
		printf("%d ", x + 1);
	return 0;
}