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
set<int> t;
multiset<int> dif;

void pr() {
    if(t.size() <= 1) {
        printf("0\n");
        return;
    }
    auto it = t.end();
    it--;
    int ret = *it-*t.begin();
    if(!dif.empty()) {
        it = dif.end();
        it--;
        ret -= *it;
    }
    printf("%d\n", ret);
}

void add(int x) {
    auto it = t.lower_bound(x);
    auto itl = it;
    if(it!=t.begin()) {
        itl--;
    }
    if(it!=t.end() && it!=t.begin()) {
        int was = *it-*itl;
        dif.erase(dif.find(was));
    }
    if(it!=t.begin()) {
        dif.insert(x-*itl);
    }
    if(it!=t.end()) {
        dif.insert(*it-x);
    }
    t.insert(x);
}

void rem(int x) {
    t.erase(t.find(x));
    auto it = t.lower_bound(x);
    auto itl = it;
    if(it!=t.begin()) {
        itl--;
    }
    if(it!=t.end() && it!=t.begin()) {
        int was = *it-*itl;
        dif.insert(was);
    }
    if(it!=t.begin()) {
        dif.erase(dif.find(x-*itl));
    }
    if(it!=t.end()) {
        dif.erase(dif.find(*it-x));
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    srt(a);
    for(auto x : a) t.insert(x);
    forn(i,1,n) dif.insert(a[i]-a[i-1]);
    pr();
    while(q--) {
        int tp, x;
        scanf("%d %d", &tp, &x);
        if(tp == 1) add(x);
        else rem(x);
        pr();
    }
    
    
    
}