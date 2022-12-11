#include <bits/stdc++.h>
using namespace std;

char v1[100005], v2[100005], v3[100005], v4[100005];
char buf[1000005];

map<string, int> mp;

int getidx(const char *val)
{
	if (val[0] == '?') return 0;
	else return mp.emplace(val, mp.size() + 1).first->second;
}

struct oper
{
	int t1, t2, t4;
	char t3;
	string num;
};

oper opers[5005];
bool mem[5005];
int n;

int operation(bool a1, bool a2, char op)
{
	if (op == 'A') return a1 && a2;
	else if (op == 'O') return a1 || a2;
	else return a1 ^ a2;
}

int calc(int dig, bool val)
{
	mem[0] = val;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (opers[i].num.empty())
		{
			mem[opers[i].t1] = operation(mem[opers[i].t2], mem[opers[i].t4], opers[i].t3);
		}
		else
		{
			mem[opers[i].t1] = opers[i].num[dig] == '1';
		}
		res += mem[opers[i].t1];
	}
	return res;
}

int main()
{
	int m;
	scanf("%d%d ", &n, &m);

	for (int i = 0; i < n; i++)
	{
		fgets(buf, 1000005, stdin);

		int ret = sscanf(buf, "%s := %s %s %s", v1, v2, v3, v4);
		if (ret == 2)
		{
			opers[i].t1 = getidx(v1);
			opers[i].num = v2;
		}
		else
		{
			opers[i].t1 = getidx(v1);
			opers[i].t2 = getidx(v2);
			opers[i].t3 = v3[0];
			opers[i].t4 = getidx(v4);
		}
	}

	string lo, hi;

	for (int i = 0; i < m; i++)
	{
		int r1 = calc(i, true), r2 = calc(i, false);

		if (r1 > r2)
		{
			lo.push_back('0'); hi.push_back('1');
		}
		else if (r1 < r2)
		{
			lo.push_back('1'); hi.push_back('0');
		}
		else
		{
			lo.push_back('0'); hi.push_back('0');
		}
	}

	printf("%s\n%s\n", lo.c_str(), hi.c_str());
}