#include <bits/stdc++.h>
#define adj_list vector<vi>
#define endl "\n"
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mod2 1000000021
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pair<int, int> >
#define pl pair<ll, ll>
#define pll pair<ll, pair<ll, ll> >
#define vi vector<int>
#define vl vector<ll>
#define primepow 3
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int m, n;
string a1[2100], a2[2100];
pair<ll, ll> hashes1[2100], hashes2[2100];
ll ans[2][1000000];

ll pow1(ll a, ll b, ll m)
{
	if (b < 1e6 and m == mod and ans[0][b] != -1)
		return ans[0][b];
	if (b < 1e6 and m == mod2 and ans[1][b] != -1)
		return ans[1][b];
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = pow1(a, b/2, m);
		x *= x;
		x %= m;
		if (b%2)
		{
			x *= a;
			x %= m;
		}
		if (m == mod)
			ans[0][b] = x;
		else
			ans[1][b] = x;
		return x;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin>>n>>m;

	for (int i = 0; i < n; i++)
		cin>>a1[i];

	for (int i = 0; i < m; i++)
		cin>>a2[i];

	for (int i = 0; i <= 1000000; i++)
		ans[0][i] = ans[1][i] = -1;

	for (int i = 0; i < 2000; i++)
	{
		hashes1[i].first = hashes2[i].first = hashes1[i].second = hashes2[i].second = 0;
	}

	for (int i = 0; i < m; i++)
	{
		ll init1 = 0, init2 = 0, addp = i*m;
		for (int j = 0; j < m; j++)
		{
			ll ind = a2[i][j]-'a'+1;
			init1 += (ind*pow1(primepow, j+addp, mod))%mod;
			init2 += (ind*pow1(primepow, j+addp, mod2))%mod2;
			init1 %= mod;
			init2 %= mod2;
		}
		hashes1[0].first += init1;
		hashes1[0].second += init2;
		hashes1[0].first %= mod;
		hashes1[0].second %= mod2;
		for (int j = m; j < n; j++)
		{
			ll ind1 = (a2[i][j]-'a')+1, ind2 = (a2[i][j-m]-'a')+1;
			init1 += ind1*pow1(primepow, j+addp+(j-m)*(m-1), mod);
			init2 += ind1*pow1(primepow, j+addp+(j-m)*(m-1), mod2);
			init1 += mod; init2 += mod2;
			init1 -= (ind2*pow1(primepow, j+addp-m+(j-m)*(m-1), mod))%mod;
			init2 -= (ind2*pow1(primepow, j+addp-m+(j-m)*(m-1), mod2))%mod2;
			init1 %= mod;
			init2 %= mod2;
			init1 *= pow1(primepow, m-1, mod);
			init2 *= pow1(primepow, m-1, mod2);
			init1 %= mod;
			init2 %= mod2;
			hashes1[j-m+1].first += init1;
			hashes1[j-m+1].second += init2;
			hashes1[j-m+1].first %= mod;
			hashes1[j-m+1].second %= mod2;
		}
	}

	vector< pl > v;

	for (int i = 0; i < n; i++)
	{
		ll init1 = 0, init2 = 0, addp = i*m;
		for (int j = 0; j < m; j++)
		{
			ll ind = a1[i][j]-'a'+1;
			init1 += (ind*pow1(primepow, j+addp, mod))%mod;
			init2 += (ind*pow1(primepow, j+addp, mod2))%mod2;
			init1 %= mod;
			init2 %= mod2;
		}
		for (int j = i; j >= max(0,i-m+1); j--)
		{
			hashes2[j].first += init1;
			hashes2[j].second += init2;
			hashes2[j].first %= mod;
			hashes2[j].second %= mod2;
		}
	}

	for (int i = 0; i <= n-m; i++)
	{
		for (int j = 0; j <= n-m; j++)
		{
			if (j > i)
			{
				ll diff = j-i;
				ll i1 = hashes1[i].first*pow1(primepow, diff*m, mod), i2 = hashes1[i].second*pow1(primepow, diff*m,mod2);
				i1 %= mod; i2 %= mod2;
				if (i1 == hashes2[j].first and i2 == hashes2[j].second)
				{
					cout<<(j+1)<<" "<<(i+1)<<endl;
					return 0;
				}
			}
			else
			{
				ll diff = i-j;
				ll i1 = hashes2[j].first*pow1(primepow, diff*m, mod), i2 = hashes2[j].second*pow1(primepow, diff*m,mod2);
				i1 %= mod; i2 %= mod2;
				if (i1 == hashes1[i].first and i2 == hashes1[i].second)
				{
					cout<<(j+1)<<" "<<(i+1)<<endl;
					return 0;
				}
			}
		}
	}

	return 0;
}