#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int mod = 998244353;

inline int mul(int a, int b) 
{
	return (int)((long long)a * b % mod);
}
inline int po(int a, int b) 
{
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
inline int inv(int a) 
{
	return po(a, mod - 2);
}
inline int di(int a, int b) 
{
	return mul(inv(b), a);
}
inline int fact(int n) 
{
	int res = 1;
	while (n--) res = mul(res, n + 1);
	return res;
}

vector<pair<long long, int> > d;

inline long long gcd(long long a, long long b) 
{
	while (a && b) {
		if (a > b) a %= b;
		else b %= a;
	}
	return a ? a : b;
}

void getdi(long long n, vector<pair<long long, int> > &v) 
{
	for (int i = 0; i < d.size(); ++i) {
		if (!(n % d[i].first)) {
			v.push_back(make_pair(d[i].first, 1));
			while (!((n /= d[i].first) % d[i].first)) ++(v.end() - 1)->second;
		}
	}
}

int getans(vector<pair<long long, int> > &v) 
{
	int n = v.size();
	int cnt = 0;
	for (int i = 0; i < n; ++i) cnt += v[i].second;
	int ans = fact(cnt);
	for (int i = 0; i < n; ++i) ans = di(ans, fact(v[i].second));
	return ans;
}

void query() 
{
	long long u, v;
	scanf("%lld%lld", &u, &v);
	long long GCD = gcd(u, v);
	u /= GCD;
	v /= GCD;
	vector<pair<long long, int> > udiv, vdiv;
	getdi(u, udiv);
	getdi(v, vdiv);
	int ansu = getans(udiv), ansv = getans(vdiv);
	printf("%d\n", mul(ansu, ansv));
}

int main() 
{
	long long D;
	scanf("%lld", &D);
	for (int i = 2; (long long)i * i <= D; ++i) {
		if (!(D % i)) {
			d.push_back(make_pair(i, 1));
			while (!((D /= i) % i)) ++(d.end() - 1)->second;
		}
	}
	if (D != 1) d.push_back(make_pair(D, 1));
	
	int q;
	scanf("%d", &q);
	while (q--) {
		query();
	}
	
	return 0;
}