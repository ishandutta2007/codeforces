#include <bits/stdc++.h>
using namespace std;

vector<string> vt;

int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vt.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		int j;
		for (j = 0; j < vt[i].size() && j < vt[i+1].size() && vt[i][j] == vt[i + 1][j]; j++);
		if (j == vt[i].size()) continue;
		if (j == vt[i + 1].size() || vt[i][j] > vt[i+1][j]) vt[i].resize(j);
	}

	for (int i = 0; i < n; i++) cout << vt[i] << '\n';
}