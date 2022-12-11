#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include <random>
#include <numeric>
#include <thread>
using namespace std;

#pragma warning(disable: 6031)

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		vector<int> vt(n);
		for (int& e : vt) scanf("%d", &e);
		sort(vt.begin(), vt.end(), [](int a, int b) {
			return (a & 1) < (b & 1);
		});

		int ans = 0;

		for (int i = 0; i < vt.size(); i++)
		{
			for (int j = i + 1; j < vt.size(); j++)
			{
				if (gcd(vt[i], vt[j] * 2) > 1) ++ans;
			}
		}

		printf("%d\n", ans);
	}
}