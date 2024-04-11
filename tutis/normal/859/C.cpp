/***
5
10 21 10 21 10
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll N;
	cin >> N;
	ll A[N];
	for (ll i = 0; i < N; i++)
		cin >> A[i];
	ll S[N];
	ll K[N];
	S[N - 1] = A[N - 1];
	K[N - 1] = 0;
	for (ll i = N - 2; i >= 0; i--)
	{
		S[i] = max(S[i + 1], K[i + 1] + A[i]);
		K[i] = -S[i];
		for (ll j = i; j < N; j++)
			K[i] += A[j];
	}
	cout << K[0] << " " << S[0] << "\n";
}