#include <bits/stdc++.h>
using namespace std;

int a[100];
int b[5][100];
int c[5][10];
int go[5];
int n;
bool solve (int t)
{
	int cnt = 0;
	while (t)
	{
		int w = t%10;
		if (!b[go[cnt]][w]) return false;
		cnt++;
		t /= 10;
	}
	return true;
}	
bool check (int t)
{
	for (int i = 0; i < n; i++)
	{
		go[i] = i;
	}
	if (solve(t)) return true;
	while(next_permutation(go,go+n))
	{
		if(solve(t)) return true;
	}
	return false;
}	
int main ()
{
	cin >> n;
	for (int q = 0; q < n; q++)
	for (int i = 0; i < 6; i++) {
		cin >> c[q][i];
		b[q][c[q][i]] = 1;
	}	
	int t = 1;
	while (true) {
		if (!check(t)) {
			cout << t - 1;
			return 0;
		}
		t++;
	}
}