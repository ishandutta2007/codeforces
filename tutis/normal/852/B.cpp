/***
2 1056 13
4 6
2 1
3 4
***/
/*output

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD (1000000007ll)
#define mod(x) (((x)+MOD)%MOD)
vector<ll> C;
ll N, L, M;
map<pair<vector<ll>, ll>, vector<ll>>A;
vector<ll> power(vector<ll> X, ll p)
{
	if (A.count(make_pair(X, p)))
		return A[make_pair(X, p)];
	vector<ll>pr = X;
	if (p == 0)
		return X;
	if (p <= 1000 || p % 2 == 1)
	{
		vector<ll>Y = X;
		for (ll a = 0; a < M; a++)
			X[a] = 0;
		for (ll b = 0; b < M; b++)
		{
			for (ll a = 0; a < M; a++)
			{
				X[(a + b) % M] = mod(X[(a + b) % M] + Y[a] * C[b]);
			}
		}
		vector<ll>a = power(X, p - 1);
		A[make_pair(pr, p)] = a;
		return a;
	}
	else
	{
		vector<ll>Y = power(X, p / 2);
		vector<ll>D = power(C, p / 2 - 1);
		for (ll a = 0; a < M; a++)
			X[a] = 0;
		for (ll b = 0; b < M; b++)
		{
			for (ll a = 0; a < M; a++)
			{
				X[(a + b) % M] = mod(X[(a + b) % M] + Y[a] * D[b]);
			}
		}
		A[make_pair(pr, p)] = X;
		return X;
	}
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> N >> L >> M;
	ll entry[N];
	ll cost[N];
	ll exit[N];
	L--;
	for (ll i = 0; i < N; i++)
		cin >> entry[i];
	for (ll i = 0; i < N; i++)
		cin >> cost[i];
	for (ll i = 0; i < N; i++)
		cin >> exit[i];
	vector<ll> D;
	for (ll i = 0; i < M; i++)
		D.push_back(0);
	for (ll i = 0; i < M; i++)
		C.push_back(0);
	for (ll i = 0; i < N; i++)
	{
		D[entry[i] % M] = mod(D[entry[i] % M] + 1);
		C[cost[i] % M] = mod(C[cost[i] % M] + 1);
	}
	D = power(D, L - 1);
	for (ll i = 0; i < M; i++)
		C[i] = 0;
	for (ll i = 0; i < N; i++)
	{
		C[(cost[i] + exit[i]) % M] = mod(C[(cost[i] + exit[i]) % M] + 1);
	}
	D = power(D, 1);
	cout << D[0];
}