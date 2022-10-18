#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int MaxN = 100000;
const int MaxM = 100000;

struct task
{
	int a;
	int id;

	friend inline bool operator<(const task &lhs, const task &rhs)
	{
		return lhs.a < rhs.a;
	}
};
struct student
{
	int b, c;
	int id;

	friend inline bool operator<(const student &lhs, const student &rhs)
	{
		return lhs.b < rhs.b;
	}
};

int n, m, s;
task ta[MaxM + 1];
student stu[MaxN + 1];

int outcome[MaxM + 1];

inline bool check(const int &lim)
{
	priority_queue<PII> q;

	int j = n;
	long long rest = s;
	for (int i = m; i >= 1; i -= lim)
	{
		while (j >= 1 && stu[j].b >= ta[i].a)
			q.push(PII(-stu[j].c, stu[j].id)), j--;

		if (q.empty())
			return false;

		PII v = q.top();
		q.pop();
		rest += v.first;
		if (rest < 0)
			return false;
		for (int k = i; k >= 1 && k > i - lim; k--)
			outcome[ta[k].id] = v.second;
	}
	return true;
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++)
		scanf("%d", &ta[i].a), ta[i].id = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &stu[i].b), stu[i].id = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &stu[i].c);

	sort(ta + 1, ta + m + 1);
	sort(stu + 1, stu + n + 1);

	int le = 0, ri = m + 1;
	while (le != ri)
	{
		int mid = (le + ri) >> 1;
		if (!check(mid))
			le = mid + 1;
		else
			ri = mid;
	}
	if (le == m + 1)
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		check(le);
		for (int i = 1; i <= m; i++)
			printf("%d ", outcome[i]);
		cout << endl;
	}

	return 0;
}