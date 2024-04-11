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
const int INF = 1e9;
vi code;
int n;
int easystep = 0;
int kin;
int sli;
ll cur0;
void count() {
    easystep = INF;
    kin = 0;
    sli = 0;
    cur0 = 0;
    forn(i,0,code.size()) {
        if(code[i] > 0) easystep = min(easystep, code[i]);
        else {
            ll k = -code[i];
            cur0 += k*(k+1)/2;
            if(i!=0 && i+1!=code.size()) {
                kin++;
                sli += k;
            }
        }
    }
}

void hardstep(int k) {
    vi ncode;
    if(code.back() > 0) code.pb(0);
    forn(i,0,code.size()) if(code[i] > 0) {
        code[i] -= k;
        code[i+1] -= k;
    }
    for(auto x : code) {
        if(x == 0) continue;
        else if(x > 0) ncode.pb(x);
        else {
            if(ncode.empty() || ncode.back() > 0) ncode.pb(x);
            else ncode.back() += x;
        }
    }
    ncode.back()+=k;
    if(ncode.back() == 0) ncode.pop_back();
    code = std::move(ncode);
}
char c[500500];
ll solve() {
    code.clear();
    int pt = 0;
    while(pt != n) {
        int ptr = pt+1;
        while(ptr != n && c[pt] == c[ptr]) ptr++;
        if(c[pt] == '1') code.pb(ptr-pt);
        else code.pb(pt-ptr);
        pt = ptr;
    }
    ll ans = 0;
    while(1) {
        count();
        if(easystep == INF) break;
        forn(i,0,easystep) {
            ans += ll(n)*(n+1)/2 - cur0;
            cur0 += sli+kin;
            sli+=kin;
            n--;
        }
        hardstep(easystep);
    }
    return ans;
}

ll solve2() {
    ll ans = 0;
    forn(l,0,n) forn(r,l,n) {
        int cur = 0;
        int best = 0;
        forn(i,l,r+1) {
            if(c[i]=='1') cur++;
            else cur = 0;
            best = max(cur, best);
        }
        ans += best;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    forn(l,1,9) forn(u,0,1<<l) {
//        forn(bit,0,l) if(u&(1<<bit)) c[bit] = '1';
//        else c[bit] = '0';
//        n = l;
//        string s;
//        forn(i,0,n) s.pb(c[i]);
//        ll a2 = solve2();
//        ll a1 = solve();
//        printf("%s %lld %lld\n", s.c_str(), a2,a1);
//    }
    
    scanf("%d\n", &n);
    scanf("%s", c);
    
    cout<<solve();
    
}