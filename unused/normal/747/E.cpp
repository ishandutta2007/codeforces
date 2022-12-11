#include <bits/stdc++.h>
using namespace std;

vector<string> vt[500005];

struct token
{
	string str;
	int level = 0;
};

token nexttoken()
{
	token ret;

	int ch;

	while ((ch = getchar()) != -1)
	{
		if (isalpha(ch)) ret.str.push_back(ch);
		else if (ch == ',') break;
	}

	while ((ch = getchar()) != -1)
	{
		if (isdigit(ch)) ret.level = ret.level * 10 + ch - '0';
		else break;
	}

	return ret;
}

bool parse(int depth)
{
	auto tt = nexttoken();
	if (tt.str.empty()) return false;

	vt[depth].emplace_back(move(tt.str));

	while (tt.level--) parse(depth + 1);

	return true;
}

int main()
{
	while (parse(0))
		;

	int maxdepth;
	for (maxdepth = 0; vt[maxdepth].empty() == false; maxdepth++)
		;

	printf("%d\n", maxdepth);

	for (int i = 0; i < maxdepth; i++)
	{
		for (auto &s : vt[i]) printf("%s ", s.c_str());
		printf("\n");
	}
}