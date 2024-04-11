#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct elem
{
	int score;
	string str;
	elem(int a, const char *b) : score(a), str(b) {}
	bool operator<(const elem &rhs) const
	{
		return score > rhs.score;
	}
};

vector<elem> region[10005];
char buf[15];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%s%d%d", buf, &a, &b);
		region[a].emplace_back( b, buf );
	}

	for (int i = 1; i <= m; i++)
	{
		sort(region[i].begin(), region[i].end());
		if (region[i].size() >= 3 && region[i][1].score == region[i][2].score)
		{
			printf("?\n");
		}
		else
		{
			printf("%s %s\n", region[i][0].str.c_str(), region[i][1].str.c_str());
		}
	}
}