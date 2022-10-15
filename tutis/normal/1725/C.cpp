/*input
1 2
10
*/
/*input
4 2
10 10 6 14
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unistd.h>
using namespace __gnu_pbds;
using namespace std;

#define ws(x) cerr << #x << " is " << x << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedTree;

typedef long long ll;
#define mp make_pair

ll mod = 998244353;

ll modPow(ll a, int n)
{
	if(n == 0)
		return 1;
	else if (n % 2 == 0)
	{
		return modPow((a * a) % mod, n / 2);
	}
	else
		return (a * modPow(a, n - 1)) % mod;
}

const int maxN = 3e5 + 7;
ll fact[maxN], invFact[maxN];
void precomputeFact()
{
	invFact[0] = fact[0] = 1;
	for(ll i = 1; i < maxN; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
		invFact[i] = modPow(fact[i], mod - 2);
	}
}

ll Cnk(ll n, ll k)
{
	return (((fact[n] * invFact[n - k]) % mod) * invFact[k]) % mod;
}

int main()
{
	precomputeFact();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	ll D[N];
	for(int i = 0; i < N; i++)
		cin >> D[i];

	ll circ = 0;
	for(int i = 0; i < N; i++)
		circ += D[i];

	int p = 0;
	int start = 0, end = 0;
	ll d = 0;
	while(start < N)
	{
		if(2ll * d > circ)
		{
			d -= D[start];
			start++;
		}
		else if (2ll * d < circ)
		{
			d += D[end];
			end++;
			if(end >= N)
				end -= N;
		}
		else
		{
			p++;
			d -= D[start];
			start++;
		}
	}

	// cout << "p = " << p << endl;

	p /= 2;

	ll ans = 0;
	for(ll v = 0; v <= p; v++)
	{
		if((N - 2 * v > 0) && (M <= v))
			continue;
		if(v > M)
			continue;

		// cout << "computinu su v = " << v << endl;

		// cout << "M = " << M << " v = " << v << " Cnk(M, v) = " << Cnk(M, v) << endl;
		ll diamCount = ((Cnk(p, v) * Cnk(M, v)) % mod * fact[v]) % mod;
		ll pCount = modPow(((M - v) * (M - v - 1ll)) % mod, p - v);
		ll remCount = modPow(M - v, N - 2 * p);
		// cout << "diamCount, pCount, remCount = " << diamCount << " " << pCount << " " << remCount << endl;
		ans += (((diamCount * pCount) % mod) * remCount) % mod;
		ans %= mod;
	}

	cout << ans;

	return 0;
}