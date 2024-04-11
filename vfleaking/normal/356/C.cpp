#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1000000;

int main()
{
	int n;
	static int nV[5];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		nV[a]++;
	}

	int res = 0;

	int delta;
	delta = min(nV[1], nV[2]);
	nV[1] -= delta, nV[2] -= delta, nV[3] += delta, res += delta;

	delta = nV[1] / 3;
	nV[1] -= 3 * delta, nV[0] += delta * 2, nV[3] += delta, res += delta * 2;

	delta = nV[2] / 3;
	nV[2] -= delta * 3, nV[0] += delta, nV[3] += delta * 2, res += delta * 2;

	if (nV[1] == 1)
	{
		if (nV[3] >= 1)
			nV[1]--, nV[3]--, nV[4]++, res++;
		else if (nV[4] >= 2)
			nV[1]--, nV[3] += 2, nV[4] -= 2, res += 2;
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}
	else if (nV[1] == 2)
	{
		if (nV[3] >= 2)
			nV[1] -= 2, nV[3] -= 2, nV[4] += 2, res += 2;
		else if (nV[4] >= 1)
			nV[1] -= 2, nV[3]++, nV[4]--, res += 2;
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}
	
	if (nV[2] == 1)
	{
		if (nV[4] >= 1)
			nV[2]--, nV[3] += 2, nV[4]--, res++;
		else if (nV[3] >= 2)
			nV[2]--, nV[3] -= 2, nV[4] += 2, res += 2;
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}
	else if (nV[2] == 2)
		nV[2] -= 2, nV[0]++, nV[4]++, res += 2;

	cout << res << endl;

	return 0;
}