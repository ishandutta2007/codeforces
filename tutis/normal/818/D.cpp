/**
4 1
2 1 4 2
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int P[1000001];
bool gali[10000001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, A;
	cin >> n >> A;
	int min = 0;
	for (int i = 1; i <= 1000000; i++)
		gali[i] = true;
	for (int i = 1; i <= 1000000; i++)
		P[i] = 0;
	gali[A] = false;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if (P[c] < min)
			gali[c] = false;
		P[c]++;
		if (c == A)
			min = P[A];
	}
	for (int c = 1; c <= 1000000; c++)
	{
		if (P[c] < min)
			gali[c] = false;
	}
	for (int i = 1; i <= 1000000; i++)
		if (gali[i])
		{
			cout << i;
			return 0;
		}
	cout << -1;
}