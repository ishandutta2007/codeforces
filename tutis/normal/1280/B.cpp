/*input
4
7 8
AAPAAAAA
PPPPAAAA
PPPPAAAA
APAAPPPP
APAPPAPP
AAAAPPAP
AAAAPPAA
6 5
AAAAA
AAAAA
AAPAA
AAPAP
AAAPP
AAAPP
4 4
PPPP
PPPP
PPPP
PPPP
3 4
PPPP
PAAA
PPPP

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--)
	{
		int r, c;
		cin >> r >> c;
		char A[r][c];
		bool ok = false;
		bool nieko = true;
		bool vienas = false;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				cin >> A[i][j];
				if (A[i][j] == 'A')
					ok = true;
				if (A[i][j] == 'P')
					nieko = false;
			}
		if (ok == false)
		{
			cout << "MORTAL\n";
			continue;
		}
		ok = true;
		for (int i = 0; i < r; i++)
		{
			if (A[i][c - 1] == 'P')
				ok = false;
		}
		vienas |= ok;
		ok = true;
		for (int i = 0; i < r; i++)
		{
			if (A[i][0] == 'P')
				ok = false;
		}
		vienas |= ok;
		ok = true;
		for (int i = 0; i < c; i++)
		{
			if (A[0][i] == 'P')
				ok = false;
		}
		vienas |= ok;
		ok = true;
		for (int i = 0; i < c; i++)
		{
			if (A[r - 1][i] == 'P')
				ok = false;
		}
		vienas |= ok;
		bool du = false;
		if (A[0][0] == 'A')
			du = true;
		if (A[r - 1][0] == 'A')
			du = true;
		if (A[r - 1][c - 1] == 'A')
			du = true;
		if (A[0][c - 1] == 'A')
			du = true;
		for (int i = 0; i < r; i++)
		{
			ok = true;
			for (int j = 0; j < c; j++)
				if (A[i][j] == 'P')
					ok = false;
			du |= ok;
		}
		for (int j = 0; j < c; j++)
		{
			ok = true;
			for (int i = 0; i < r; i++)
				if (A[i][j] == 'P')
					ok = false;
			du |= ok;
		}
		bool trys = false;
		for (int i = 0; i < r; i++)
			if (A[i][0] == 'A')
				trys = true;
		for (int i = 0; i < r; i++)
			if (A[i][c - 1] == 'A')
				trys = true;
		for (int i = 0; i < c; i++)
			if (A[0][i] == 'A')
				trys = true;
		for (int i = 0; i < c; i++)
			if (A[r - 1][i] == 'A')
				trys = true;
		int ans = 4;
		if (trys)
			ans = 3;
		if (du)
			ans = 2;
		if (vienas)
			ans = 1;
		if (nieko)
			ans = 0;
		cout << ans << "\n";
	}
}