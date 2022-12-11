#include "bits/stdc++.h"
using namespace std;

char str[100005];
const char *alpha = "abcdefghijklmnopqrstuvwxyz";

long long get(const char *p)
{
	int len = strlen(p);
	bool cent = len >= 3 && p[len - 3] == '.';
	long long ret = 0;
	while (*p)
	{
		char ch = *p++;
		if (ch == '.') continue;
		ret = ret * 10 + ch - '0';
	}

	if (cent == false) ret *= 100;
	return ret;
}

int main()
{
	scanf("%s",str);
	long long sum = 0;
	for (char *p = strtok(str, alpha); p; p = strtok(nullptr, alpha))
		sum += get(p);

	string cent;
	if (sum % 100)
	{
		cent += '.';
		cent.push_back('0' + sum % 100 / 10);
		cent.push_back('0' + sum % 10);
	}

	sum /= 100;

	string ans;
	do
	{
		if (ans.size() % 4 == 3) ans.push_back('.');
		ans.push_back(sum % 10 + '0');
		sum /= 10;
	} while (sum);

	reverse(ans.begin(), ans.end());
	printf("%s%s", ans.c_str(), cent.c_str());
}