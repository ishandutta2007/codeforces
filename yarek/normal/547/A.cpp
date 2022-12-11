#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int m;

bool k[1000002];

struct s
{
    long long x, y, h, a;
    void read()
    {
	cin >> h >> a >> x >> y;
    }
    
    bool step()
    {
	h = (x * (long long)h + y) % m;
	return h == a;
    }
    
    int time()
    {
	for(int i = 0; i <= m; i++)
	    if(step()) return i + 1;
	return -1;
    }
};

typedef long long ll;

pair<ll, ll> euk(ll a, ll b)
{
    if(b == 0) return make_pair(1LL, 0LL);
    auto p = euk(b, a % b);
    return make_pair(p.second, p.first - p.second * (a / b));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> m;
    s xan, abo;
    xan.read();
    abo.read();
    int t1 = xan.time(), t2 = abo.time();
    if(t1 == -1 || t2 == -1)
    {
	cout << -1 << endl;
	return 0;
    }
    if(t1 == t2)
    {
	cout << t1 << "\n";
	return 0;
    }
    int c1 = xan.time(), c2 = abo.time();
    if(c1 == -1 && c2 == -1)
    {
	cout << -1 << endl;
	return 0;
    }
    if(c1 == -1 || t1 > t2)
    {
	swap(t1, t2);
	swap(c1, c2);
    }
    if(c1 == -1)
    {
	cout << -1 << endl;
	return 0;
    }
    if(c2 == -1)
    {
	cout << ((t2 - t1) % c1 == 0 ? t2 : -1) << endl;
	return 0;
    }
    auto p = euk(c1, c2);
    long long gcd = p.first * c1 + p.second * c2;
    if(abs(t1 - t2) % gcd != 0)
    {
	cout << -1 << endl;
	return 0;
    }
    p.first *= (t1 - t2) / gcd;
    p.second *= (t1 - t2) / gcd;
    while(p.second >= 0)
    {
	p.first += c2 / gcd;
	p.second -= c1 / gcd;
    }
    while(p.second < 0)
    {
	p.first -= c2 / gcd;
	p.second += c1 / gcd;
    }
    cout << (p.second * c2 + t2) << endl;
}