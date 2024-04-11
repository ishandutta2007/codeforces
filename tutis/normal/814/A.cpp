/**
7 7
0 0 0 0 0 0 0
1 2 3 4 5 6 7
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int A[n];
	int B[k];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < k; i++)
		cin >> B[i];
	sort(B, B + k, [](int a, int b) {return a > b;});
	int id = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] == 0)
		{
			A[i] = B[id];
			id++;
		}
	}
	bool ok = true;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i + 1] <= A[i])
		{
			ok = false;
		}
	}
	if (ok)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}