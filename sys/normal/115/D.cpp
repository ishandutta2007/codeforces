#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005, p = 1000003;
int f[Maxn];
string str;
bool check1(char ch)
{
	return ch == '+' || ch == '-';
}
bool check2(char ch)
{
	return check1(ch) || ch == '*' || ch == '/';
}
void init(void)
{
	if ((check2(str[0]) && !check1(str[0])) || !isdigit(str[str.size() - 1]))
	{
		puts("0");
		exit(0);
	}
	str = "#" + str + "#";
	string tmp;
	int siz = str.size();
	for (int i = 1; i < siz - 1; i++)
	{
		if (check2(str[i]) && !check2(str[i - 1])) tmp += '0';
		if (check1(str[i]) && check2(str[i - 1])) tmp += '1';
		else if (check2(str[i - 1]) && check2(str[i]))
		{
			puts("0");
			exit(0);
		}
	}
	str = tmp;
}
int main()
{
	cin >> str;
	init();
	int siz = str.size();
	f[1] = 1;
	for (int i = 0; i < siz; i++)
	{
		if (str[i] == '1')
			for (int j = i + 1; j >= 1; j--)
				f[j + 1] = f[j];
		if (str[i] == '0')
			for (int j = i + 1; j >= 0; j--)
				(f[j + 1] = f[j + 2] + f[j]) %= p;
	}
	printf("%d", f[1]);
	return 0;
}