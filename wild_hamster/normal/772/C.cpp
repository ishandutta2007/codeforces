#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <assert.h>
#include <list>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 10000000
#define SQ 317
#define MAG 33554431
#define RED 0
#define BLUE 1
#define ALP 26
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,k,l,m,r,x,y,K,tot,sz,cur,sum,n,c, maxlvl,q, start_pnt;
string s,t;
ll prime[200500], used[200500], dp[200500];
vector<ll> f;
double p;
ll binpow(ll x, ll y, ll md)
{
    if (y == 0)
        return 1%md;
    ll tmp = binpow(x, y/2, md);
    tmp = (tmp*tmp)%md;
    if (y%2 == 0)
        return tmp;
    return (x*tmp)%md;
}
ll gcd(ll a, ll b)
{
    return (b==0?a:gcd(b,a%b));
}
int gcdex (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdex (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("input.txt","w",stdout);
 	//cin >> s;
 	for (i = 2; i <= 200000; i++)
    {
        prime[i] = 1;
    }
    for (i = 2; i <= 200000; i++)
        if (prime[i])
            for (j = i*2; j <= 200000; j+=i)
                prime[j] = 0;
 	cin >> n >> m;
 	for (i = 0; i < n; i++)
    {
        cin >> x;
        used[x] = 1;
    }
    ll lst;
    if (prime[m])
    {
        for (i = 1; i <= m-1; i++)
        {
            if (!used[i])
            {
                if (f.size() == 0)
                {
                    f.push_back(i);
                    lst = i;
                }
                else
                {
                    x = (i*binpow(lst, m-2, m))%m;
                    f.push_back(x);
                    lst = i;
                }
            }
        }
        if (!used[0])
            f.push_back(0);
        cout << f.size() << endl;
        for (i = 0; i < f.size(); i++)
            cout << f[i] << " ";
        return 0;
    }
    ll ans = -1, idx;
    for (i = 1; i <= m-1; i++)
    if (prime[i] && m%i == 0)
    {
        ll cnt = 0;
        for (j = i; j <= m-1; j += i)
            if (!used[j])
                cnt++;
        if (cnt > ans)
        {
            ans = cnt;
            idx = i;
        }
    }

    for (i = 2; i <= m; i++)
        if (m%i == 0)
        {
            ll v = m/i;
            ll tmp = 0;
            for (j = v; j <= m-1; j += v)
            {
                ll g = gcd(j/v, i);
                if (g == 1)
                    dp[i]+=1-used[j];
                else
                    tmp = max(tmp, dp[i/g]);
            }
            dp[i] += tmp;
        }
    ll x = m;
    ll next_rev = -1, last_v, last_md;
    while (x != 1)
    {
        ll v = m/x;
        for (j = 1; j <= x-1; j++)
        if (!used[j*v] && gcd(j, x) == 1)
        {
            if (next_rev == -1)
            {
                f.push_back(j*v);
                int vv = j;
                int xx, y;
                int g = gcdex (vv, x, xx, y);
                xx = (xx % x + x) % x;
                last_v = v;
                last_md = x;
                next_rev = xx;
            }
            else
            {
                next_rev = (j*v/last_v*next_rev)%last_md;
                f.push_back(next_rev);
                int vv = j;
                int xx, y;
                int g = gcdex (vv, x, xx, y);
                xx = (xx % x + x) % x;

                last_v = v;
                last_md = x;
                next_rev = xx;
            }
        }
        ll ans = -1, idx;
        for (j = 1; j <= x-1; j++)
        if (x%j == 0)
        {
            if (dp[j] > ans)
                ans = dp[j], idx = j;
        }
        x = idx;
    }
    if (!used[0])
        f.push_back(0);
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    return 0;
}