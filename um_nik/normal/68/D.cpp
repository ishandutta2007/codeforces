#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <unordered_map>
using namespace std;

int h, q;
char s[10];
unordered_map<int, int> a;
double ans;

void add(int v, int x)
{
	if (a.count(v) == 0)
		a[v] = x;
	else
		a[v] += x;
	return;
}
void addToRoot(int v, int x)
{
	while(v > 0)
	{
		add(v, x);
		v >>= 1;
	}
	return;
}
int getVal(int v)
{
	if (a.count(v) == 0) return 0;
	return a[v];
}

void solve(int v, double p, int prevMax)
{
	if (v >= (1 << h))
	{
		ans += p * getVal(v);
		return;
	}
	int curVal = getVal(v);
	int leftVal = getVal(2 * v), rightVal = getVal(2 * v + 1);
	p /= 2;
	if (leftVal * 2 <= curVal || leftVal <= prevMax)
		ans += p * max(prevMax, curVal - leftVal);
	else
		solve(2 * v, p, max(prevMax, curVal - leftVal));
	if (rightVal * 2 <= curVal || rightVal <= prevMax)
		ans += p * max(prevMax, curVal - rightVal);
	else
		solve(2 * v +1, p, max(prevMax, curVal - rightVal));
	return;
}

double getAns()
{
	ans = 0;
	solve(1, 1, -1);
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &h, &q);
	while(q--)
	{
		scanf(" %s ", s);
		if (s[0] == 'a')
		{
			int v, x;
			scanf("%d%d", &v, &x);
			addToRoot(v, x);
		}
		else
			printf("%.12lf\n", getAns());
	}

	return 0;
}