/**
5
4 4 2 3 1
5 4 5 3 1
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int A[n], B[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	int P[n];
	for (int i = 0; i < n; i++)
		P[i] = A[i];
	int C[n + 1];
	for (int i = 0; i <= n; i++)
	{
		C[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		C[A[i]]++;
	}
	int D[n + 1];
	for (int i = 0; i <= n; i++)
	{
		D[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		D[B[i]]++;
	}
	int id;
	for (int i = 1; i <= n; i++)
	{
		if (C[i] == 0)
		{
			id = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (C[A[i]] == 2)
		{
			P[i] = id;

			int skb = 0;
			int ska = 0;
			for (int i = 0; i < n; i++)
			{
				if (P[i] != A[i])
					ska++;
				if (P[i] != B[i])
					skb++;
			}
			if (ska == 1 && skb == 1)
			{
				for (int i = 0; i < n; i++)
					cout << P[i] << " ";
				return 0;
			}
			P[i] = A[i];
		}
	}
	return 0;
}