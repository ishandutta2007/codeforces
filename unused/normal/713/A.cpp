#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

using ll = long long;
unordered_map<int, int> mp[20];

void process(long long num, int diff)
{
	int z = 0;
	int mul = 1;
	while (num)
	{
		z = z + (num & 1) * mul;
		num /= 10;
		mul *= 2;
	}
	mp[to_string(num).size() - 1][z] += diff;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char ch;
		int n;
		scanf(" %c", &ch);
		if (ch == '+' || ch == '-')
		{
			int diff = ch == '+' ? 1 : -1;
			ll num; scanf("%lld", &num);
			process(num, diff);
		}
		else
		{
			char num[100];
			scanf("%s", num);
			int ans = 0;
			int len = strlen(num);
			int target = strtol(num, nullptr, 2);

			for (int i = 0; i < 20; i++)
				ans += mp[i][target];
			printf("%d\n", ans);
		}
	}
}