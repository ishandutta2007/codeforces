#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

int answer = (int)1e9;
int pr[2][3];
int cost[3];
int pay[3];
int tot = 0;
const int maxValue[] = {10000, 200, 100};

bool check()
{
	int a = pr[0][0] + pay[0];
	int b = pr[1][0];

	int da = max(pr[1][1] - (pr[0][2] + pay[2]), 0);
	int db = max(pr[0][1] + pay[1] - pr[1][2], 0);
	if (db == 0)
		return false;
	int moves = (b + db - 1) / db;
	if (a - da * moves > 0)
		return true;
	return false;
}

void relax()
{
	if (check())
		answer = min(answer, tot);
}

void brute(int pos)
{
	if (tot > answer)
		return;
	if (pos == 3)
	{
		relax();
		return;
	}
	for (int value = maxValue[pos]; value >= 0; value--)
	{
		pay[pos] = value;
		tot += value * cost[pos];
		brute(pos + 1);
		tot -= value * cost[pos];
	}
}

int main()
{

	for (int i = 0; i < 2; i++)
		for (int s = 0; s < 3; s++)
			scanf("%d", &pr[i][s]);

	for (int i = 0; i < 3; i++)
		scanf("%d", &cost[i]);
	brute(0);
	cout << answer;

	return 0;
}