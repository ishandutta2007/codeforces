#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 998244353;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    char c[200500];
    scanf("%s", c);
    int d2 = 0;
    int C = 0;
    int A = 0;
    for(int i = 0; i < n; i += 2) {
        if(c[i] == 'w') {
            if(c[i+1] == 'b') C++;
            else if(c[i+1] == '?') {
                A++;
                d2++;
            }
        }
        else if(c[i] == 'b') {
            if(c[i+1] == 'w') C--;
            else if(c[i+1] == '?') {
                d2++;
                C--;
                A++;
            }
        }
        else if(c[i] == '?') {
            if(c[i+1] == 'w') {
                d2++;
                C--;
                A++;
            }
            else if(c[i+1] == 'b') {
                d2++;
                A++;
            }
            else if(c[i+1] == '?') {
                d2 += 2;
                A += 2;
                C--;
            }
        }
    }
    vll fac(A+1,1);
    vll ifac(A+1,1);
    forn(i,1,A+1) {
        fac[i] = fac[i-1] * i % mod;
        ifac[i] = ifac[i-1] * invmod(i, mod) % mod;
    }
    ll ev = 0;
    ll ng = 0;
    forn(i,0,A+1) {
        if (i % 2 != abs(C) % 2) continue;
        ll cnk = fac[A] * ifac[i] % mod * ifac[A-i] % mod;
        ll op = abs(i + C) / 2;
        ev = (ev + cnk * op) % mod;
        ng = (ng + cnk) % mod;
    }
    cout << ev * invmod(ng, mod) % mod;
}