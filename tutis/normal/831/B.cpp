/***
qwertyuiopasdfghjklzxcvbnm
veamhjsgqocnrbfxdtwkylupzi
TwccpQZAvb2017
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	string a, b, c;
	cin >> a >> b >> c;
	map<char, char>X;
	for (int i = 0; i < 26; i++)
		X[a[i]] = b[i];
	for (int i = 0; i < 26; i++)
		X[toupper(a[i])] = toupper(b[i]);
	for (char d : c)
	{
		if (X.count(d))
			cout << X[d];
		else
			cout << d;
	}
}