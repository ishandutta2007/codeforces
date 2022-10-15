#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t N;
	cin >> N;
	int64_t A[N];
	for (int64_t i = 0; i < N; i++)
		cin >> A[i];
	int64_t D[N];
	D[N - 1] = 0;
	int64_t k = -1;
	for (int64_t i = 0; i < N - 1; i++)
	{
		k *= -1;
		D[i] = k * abs(A[i] - A[i + 1]);
	}
	int64_t mak[N];
	mak[0] = D[0];
	mak[1] = mak[0] + D[1];
	for (int64_t i = 2; i < N; i++)
	{
		if (i % 2 == 1)
		{
			mak[i] = mak[i - 1] + D[i];
		}
		else
		{
			mak[i] = max(mak[i - 1] + D[i], D[i]);
		}
	}
	int64_t a = *max_element(mak, mak + N);
	mak[0] = -INT_MAX;
	mak[1] = -D[1];
	for (int64_t i = 2; i < N; i++)
	{
		if (i % 2 == 0)
		{
			mak[i] = mak[i - 1] - D[i];
		}
		else
		{
			mak[i] = max(mak[i - 1] - D[i], -D[i]);
		}
	}
	a = max(a, *max_element(mak, mak + N));
	cout << a;
	return 0;
}