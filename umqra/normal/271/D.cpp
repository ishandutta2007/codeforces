#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define mp make_pair

set <pll> h;
const ll p1 = 913183;
const ll p2 = (ll)1e9 + 7;
const ll mod = (ll)1e9 + 9;

pll deg[3000];
int g[30];

ll add(ll a, ll b, ll mod)
{
    ll c = a + b;   
    if (c >= mod)
        return c - mod;
    return c;
}

ll mult(ll a, ll b, ll mod)
{
    return (a * b) % mod;
}

pll add(pii a, pii b)
{
    return mp(add(a.X, b.X, mod), add(a.Y, b.Y, mod));
}

pll mult(pii a, pii b)
{
    return mp(mult(a.X, b.X, mod), mult(a.Y, b.Y, mod));
}

void calc()
{
    deg[0] = mp(1, 1);
    for (int i = 1; i <= 2000; i++)
        deg[i] = mult(deg[i - 1], mp(p1, p2));
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    calc();
    string str;
    string good;
    int k;
    int ans = 0;
    cin >> str >> good >> k;
    for (int i = 0; i < 26; i++)
        g[i] = (good[i] == '1' ? 0 : 1);

    for (int i = 0; i < (int)str.length(); i++)
    {
        int cnt = 0;
        pii curHash = mp(0, 0);
        int ind = i;
        while (ind >= 0)
        {              
            int code = str[ind] - 'a' + 1;
            cnt += g[str[ind] - 'a'];
            if (cnt > k)
                break;                          
            curHash = add(curHash, mult(deg[i - ind], mp(code, code)));
            //cout << curHash.X << ' ' << curHash.Y << endl;
            if (h.find(curHash) == h.end())
            {                                    
                ans++;
                h.insert(curHash);
            }
            ind--;         
        }
    }

    printf("%d", ans);

    return 0;
}