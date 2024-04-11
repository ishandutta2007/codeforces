#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char str[1000];

int ans1, ans2;

void get1(string s)
{
	for (auto p = strtok(&s[0], "_"); p; p = strtok(nullptr, "_"))
	{
		ans1 = max<int>(ans1, strlen(p));
	}
}

void get2(string s)
{
	for (auto p = strtok(&s[0], "_"); p; p = strtok(nullptr, "_"))
	{
		if (p[0]) ans2++;
	}
}

int main()
{
	scanf("%*d%s", str);

	string str2;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(' || str[i] == ')') str2.push_back('_');
		str2.push_back(str[i]);
		if (str[i] == '(' || str[i] == ')') str2.push_back('_');
	}

	strcpy(str, str2.c_str());

	bool nowparen = str[0] == '(';

	vector<string> s1, s2;

	for (auto p = strtok(str, "()"); p; p = strtok(nullptr, "()"))
	{
		(nowparen ? s2 : s1).push_back(p);
		nowparen ^= true;
	}

	for (auto &&s : s1) get1(s);
	for (auto &&s : s2) get2(s);

	printf("%d %d", ans1, ans2);
}