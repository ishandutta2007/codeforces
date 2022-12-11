#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

set<int> qone[300005];
set<pair<int, int>> qtwo;

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	int now = 0;
	int mtime = 1;
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		switch (a)
		{
		case 1:
			qone[b].insert(mtime);
			qtwo.emplace(mtime, b);
			++mtime;
			now++;
			break;
		case 2:
			while (qone[b].empty() == false)
			{
				int t = *qone[b].begin();
				qone[b].erase(qone[b].begin());
				qtwo.erase({ t, b });
				now--;
			}
			break;
		case 3:
			while (qtwo.empty() == false && qtwo.begin()->first <= b)
			{
				qone[qtwo.begin()->second].erase(qtwo.begin()->first);
				qtwo.erase(qtwo.begin());
				now--;
			}
			break;
		}
		printf("%d\n", now);
	}

	fflush(stdout);
	_Exit(0);
}