#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

ll m;
ll h1, a1, x, y;
ll h2, a2, xx, yy;
ll p1, p2;
ll q1, q2;

int main()
{
	cin >> m;
	cin >> h1 >> a1;
	cin >> x >> y;
	cin >> h2 >> a2;
	cin >> xx >> yy;

	p1 = p2 = q1 = q2 = -1;

	for (int i = 1; i <= 2 * m; i++)
	{
		h1 = (h1 * x + y) % m;
		h2 = (h2 * xx + yy) % m;
		if (h1 == a1)
		{
			if (p1 == -1)
				p1 = i;
			else if (p2 == -1)
				p2 = i;
		}
		if (h2 == a2)
		{
			if (q1 == -1)
				q1 = i;
			else if (q2 == -1)
				q2 = i;
		}
	}

	if (p1 == -1 || q1 == -1)
	{
		printf("-1\n");
		return 0;
	}

	if (p2 == -1)
	{
		if (q2 == -1)
		{
			if (p1 == q1)
				cout << p1 << endl;
			else
				printf("-1\n");
			return 0;
		}
		q2 = q2 - q1;
		if (p1 >= q1 && (p1 - q1) % q2 == 0)
			cout << p1 << endl;
		else
			printf("-1\n");
		return 0;
	}
	p2 = p2 - p1;
	if (q2 == -1)
	{
		if (q1 >= p1 && (q1 - p1) % p2 == 0)
			cout << q1 << endl;
		else
			printf("-1\n");
		return 0;
	}
	q2 = q2 - q1;
	while(p1 < q1) p1 += p2;
	for (int i = 0; i <= q2; i++)
	{
		if ((p1 - q1) % q2 == 0)
		{
			cout << p1 << endl;
			return 0;
		}
		p1 += p2;
	}
	printf("-1\n");

	return 0;
}