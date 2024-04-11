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

const long long mod = 1000000007;
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
int k;
vi kbuild(int n) {
    vi res;
    while(n > 0) {
        res.pb(n%k);
        n/=k;
    }
    return res;
}

int kun(vi & a) {
    int cur = 0;
    int dk = 1;
    for(auto x : a) {
        cur += x*dk;
        dk*=k;
    }
    return cur;
}

vi ksum(const vi & a, const vi & b) {
    vi res;
    forn(i,0,max(a.size(), b.size())) {
        res.pb(0);
        if(i < a.size()) res.back() = a[i];
        if(i<b.size()) res.back() = (res.back() + b[i])%k;
    }
    return res;
}

vi krev(vi &a) {
    vi res;
    for(auto x : a) res.pb((k-x)%k);
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d %d", &n, &k);
        vi r(1,0);
        int sg = 1;
        forn(i,0,n) {
            vi x = kbuild(i);
            if(sg==-1) x = krev(x);
            x = ksum(x, r);
            printf("%d\n", kun(x));
            fflush(stdout);
            int res;
            scanf("%d", &res);
            if(res==1) break;
            sg = -sg;
            r = ksum(x, krev(r));
        }
    }
    
}