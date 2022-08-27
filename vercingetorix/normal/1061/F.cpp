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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int req(int a, int b, int c) {
    printf("? %d %d %d\n", a+1, b+1, c+1);
    fflush(stdout);
    string s;
    cin>>s;
    if(s[0] == 'Y') return 1;
    else return 0;
}
int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n,k;
//    scanf("%d %d", &n, &k);
    cin>>n>>k;
    int lev = 0;
    ll onl = 1;
    ll cnt = 1;
    while(cnt < n) {
        onl *= k;
        cnt += onl;
        lev++;
    }
    int l = 0;
    int r = 0;
    vi a;
    while(a.size() < 2*lev+1) {
        l = gen()%n;
        r = gen()%n;
        a.clear();
        forn(i,0,n) {
            if(req(l,i,r)) a.pb(i);
        }
    }
    set<pi> ord;
    ord.insert(mp(0,l));
    ord.insert(mp(1e9,r));
    for(auto x : a) {
        if(x==l || x==r) continue;
        auto it = ord.begin();
        while(1) {
            auto was = *it;
            it++; 
            auto cur = *it;
            if(req(was.second, x, cur.second)) {
                ord.insert(mp((was.first+cur.first)/2, x));
                break;
            }
        }
    }
    auto it = ord.begin();
    forn(i,0,lev) it++;
    printf("! %d", it->second+1);
    fflush(stdout);
    
}