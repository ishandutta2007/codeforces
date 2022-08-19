#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 1010;
int n;
int a[N];

bool isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		for (char c : s)
			if (isVowel(c))
				a[i]--;
		if (a[i] != 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}