#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

typedef unsigned long long ull;
ull gcd (ull a, ull b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    map<ll, vi> cnt;
    vector<vector<ull>> f(n);
    forn(i,0,n) {
        f[i] = factor(a[i]);
        srt(f[i]);
        if(f[i][0] == f[i].back()) cnt[f[i][0]].pb(i);
    }
    set<ll> good;
    for(auto x : cnt) if(x.second.size() >= 2) good.insert(x.first);
    if(k >= good.size()*2) {
        vi taken(n,0);
        int did = good.size()*2;
        for(auto x : good) {
            taken[cnt[x][0]] = 1;
            taken[cnt[x][1]] = 1;
        }
        if(did<k)
        forn(i,0,n) {
            if(taken[i]) continue;
            int bad = 0;
            for(auto x : f[i]) {
                if(good.find(x) == good.end()) {
                    bad = 1;
                    break;
                }
            }
            if(bad == 0) {
                did++;
                taken[i] = 1;
                if(did == k) break;
            }
        }
        if(did < k) {
            printf("0\n");
        }
        else {
            forn(i,0,n) if(taken[i]) printf("%lld ", a[i]);
        }
    }
    else if(k%2 == 0) {
        vi taken(n,0);
        int did = 0;
        for(auto x : good) {
            taken[cnt[x][0]] = 1;
            taken[cnt[x][1]] = 1;
            did += 2;
            if(did == k) break;
        }
        forn(i,0,n) if(taken[i]) printf("%lld ", a[i]);
    }
    else {
        vi man(n,0);
        for(auto x : good) {
            man[cnt[x][0]] = 1;
            man[cnt[x][1]] = 1;
        }
        pi best = mp(10000, -1);
        forn(i,0,n) {
            if(man[i]) continue;
            int bad = 0;
            int cp = 0;
            forn(j,0,f[i].size()) {
                if(j>0 && f[i][j] == f[i][j-1]) continue;
                cp++;
                if(good.find(f[i][j]) == good.end()) {
                    bad = 1;
                    break;
                }
            }
            if(bad == 0) best = min(best, mp(cp, i));
        }
        if(k < 2*best.first+1) {
            printf("0\n");
        }
        else {
            int i = best.second;
            vi taken(n,0);
            taken[i] = 1;
            int did = 1;
            forn(j,0,f[i].size()) {
                if(j>0 && f[i][j] == f[i][j-1]) continue;
                ll x = f[i][j];
                taken[cnt[x][0]] = 1;
                taken[cnt[x][1]] = 1;
                did += 2;
            }
            if(did < k)
            for(auto x : good) {
                if(taken[cnt[x][0]] == 1) continue;
                taken[cnt[x][0]] = 1;
                taken[cnt[x][1]] = 1;
                did+=2;
                if(did == k) break;
            }
            forn(i,0,n) if(taken[i]) printf("%lld ", a[i]);
        }
    }
    
    
    
}