#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

const int N = 111;
int n, k;
int a[N];
string b[N];

int solve(int x)
{
	return x + ((x - 1) / k) * 5;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		a[(int)b[i].length()]++;
	}
	string s;
	cin >> s;
	int x = -1;
	for (int i = 0; i < n; i++)
		if (s == b[i])
			x = (int)b[i].length();
	if (x == -1) throw;
	int sum = 0;
	for (int i = 0; i < x; i++)
		sum += a[i];
	printf("%d %d\n", solve(sum + 1), solve(sum + a[x]));

	return 0;
}