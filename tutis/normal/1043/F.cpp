/*input
7
30 60 21 42 70 15 30
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pd[300002];
int fact(int n)
{
	int ret = 1;
	while (n != 1)
	{
		int p = pd[n];
		int a = 0;
		while (n % p == 0)
		{
			n /= p;
			a++;
		}
		ret *= p;
	}
	return ret;
}
int Kiekis[300002];
const ll modulo = 1000000007;
ll mod(ll x, ll m = modulo)
{
	x %= m;
	x += m;
	x %= m;
	return x;
}
ll power(ll x, ll a)
{
	x = mod(x);
	a = mod(a, modulo - 1);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, -1);
}
ll choose(ll n, ll k)
{
	if(k<0 || n<0 || n<k)
		return 0;
	if(k==0 || k==n)
		return 1;
	ll a=1;
	ll b=1;
	for(int i=1;i<=k;i++)
	{
		a=mod(a*(n+1-i));
		b=mod(b*i);
	}
	return mod(a*inv(b));
}
int main()
{
	for (int t = 2; t < 300002; t++)
	{
		if (pd[t] == 0)
		{
			for (int j = t; j < 300002; j += t)
			{
				if (pd[j] == 0)
					pd[j] = t;
			}
		}
	}
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
	{
		cin >> i;
		i = fact(i);
		if (i == 1)
		{
			cout << "1\n";
			return 0;
		}
		Kiekis[i] = 1;
	}
	{
		int G = 0;
		for (int i : a)
			G = __gcd(G, i);
		if (G != 1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	const int mx = *max_element(a, a + n) + 5;
	vector<int>b;
	for(int i=1;i<=mx;i++)
		if(Kiekis[i])
			b.push_back(i);
	for(int t=1;;t++)
	{
		ll dp[mx + 1];
		for(int i=mx;i>=1;i--)
		{
			int C=0;
			for(int j=i;j<=mx;j+=i)
			{
				C+=Kiekis[j];
			}
			dp[i]=choose(C,t);
			for(int k=2;i*k<=mx;k++)
			{
				dp[i]=mod(dp[i]-dp[i*k]);
			}
		}
		if(dp[1]!=0)
			{
				cout<<t<<"\n";
				return 0;
			}
	}
}