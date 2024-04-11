#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long A[100000];
long long B[100000];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	long long N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	long long G = A[0];
	for (int i = 1; i < N; i++)
	{
		G = __gcd(G, A[i]);
	}
	if (G != 1)
	{
		cout << "YES\n0";
		return 0;
	}
	bool lyg = false;
	for (int i = 0; i < N; i++)
	{
		A[i] = A[i] % 2;
		if (A[i] == 0)
			lyg = true;
	}
	int nel = 0;
	int ats = 0;
	if (!lyg)
	{
		if (N % 2 == 0)
		{
			cout << "YES\n" << N / 2;
			return 0;
		}
		else
		{
			cout << "YES\n" << N / 2 + 2;
			return 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 1)
			nel++;
		else
		{
			if (nel % 2 == 0)
				ats += nel / 2;
			else
				ats += (nel + 1) / 2 + 1;
			nel = 0;
		}
	}
	if (nel % 2 == 0)
		ats += nel / 2;
	else
		ats += (nel + 1) / 2 + 1;
	nel = 0;
	cout << "YES\n" << ats;
	return 0;
}