#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;
	bool skyle[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		skyle[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		int h;
		cin >> h;
		skyle[h] = true;
	}
	int kaulas = 1;
	for (int i = 0; i < K; i++)
	{
		if (skyle[kaulas])
			break;
		int u, v;
		cin >> u >> v;
		if (u == kaulas)
			kaulas = v;
		else if (v == kaulas)
			kaulas = u;
		if (skyle[kaulas])
			break;
	}
	cout << kaulas;
	return 0;
}