#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

string s;
int len;

string sum(string a, string b)
{
	int la = a.length(), lb = b.length();
	a.insert(0, "0");
	b.insert(0, "0");
	if (la>lb)b.insert(0,la-lb, '0');
	else if (la<lb)a.insert(0,lb-la, '0');
	la = a.length(), lb = b.length();

	for (int i = la - 1; i >= 0; i--)
	{
		if (i == la - 1)a[i] += b[i] - '0';
		else
		{
			a[i] += b[i] - '0' + (a[i + 1] - '0') / 10;
			a[i + 1] = (a[i + 1] - '0') % 10 + '0';
		}
	}
	if (a[0] == '0')a.erase(a.begin());
	return a;
}

string pre(int a)
{
	string x = s.substr(0, a), y = s.substr(a, len - a);
	return sum(x, y);
}

string _min(string a, string b)
{
	int la = a.length(), lb = b.length();
	if (la>lb)return b;
	if (la<lb)return a;
	for (int i = 0; i<la; i++)
	{
		if (a[i]<b[i])return a;
		if (a[i]>b[i])return b;
	}
	return a;
}

int main()
{
	string ans;
	cin >> len >> s;
	int st = len / 2;
	while (s[st] == '0'&&s[len - st] == '0')st--;
	if (s[st] != '0'&&s[len - st] != '0')cout << _min(pre(st), pre(len - st));
	else if (s[st] != '0')cout << pre(st);
	else cout << pre(len - st);
	return 0;
}