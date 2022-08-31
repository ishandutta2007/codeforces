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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    readv(b,n);
    int q;
    vpi qo;
    scanf("%d", &q);
    vll ans(q, -1);
    forn(i,0,q) {
        int x;
        scanf("%d", &x);
        qo.pb(mp(x,i));
    }
    srt(qo);
    b[0] = 0;
    ll cur = 0;
    vll op(n,0);
    forn(i,0,n) {
        if(a[i] != b[i]) {
            cur+=abs(a[i]-b[i]);
            op[i] = b[i] - a[i];
            for(int j = i; j < n; j+=(i+1)) a[j] += op[i];
        }
    }
    forn(i,0,n) {
        a[i] = 0;
        b[i] = 0;
    }
    b[0] =1;
    vll op2(n,0);
    forn(i,0,n) {
        if(a[i] != b[i]) {
            op2[i] = b[i] - a[i];
            for(int j = i; j < n; j+=(i+1)) a[j] += op2[i];
        }
    }
    vpll ev;
    ll k = 0;
    forn(i,0,n) {
        if(op2[i] > 0) {
            if(op[i] < 0) {
                k -= op2[i];
                ev.pb(mp(-op[i]/op2[i]+1, i));
            }
            else k += op2[i];
        }
        else if(op2[i] < 0) {
            if(op[i] > 0) {
                k += op2[i];
                ev.pb(mp(-op[i]/op2[i]+1, i));
            }
            else k -= op2[i];
        }
    }
    srt(ev);
    int pt = 0;
    forn(it,0,q) {
        ll x = qo[it].first;
        while(pt < ev.size() && ev[pt].first <= x) {
            int i = ev[pt].second;
            cur -= abs(op[i]);
            op[i] += x*op2[i];
            cur += abs(op[i]);
            k += 2*abs(op2[i]);
            cur -= x * abs(op2[i]);
            pt++;
        }
        ans[qo[it].second] = k*x+cur;
    }
    forn(i,0,q) printf("%lld\n", ans[i]);
    
    
}