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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    vi r;
    int imax = 0;
    forn(i,0,n) if(a[i] > a[imax]) imax = i;
    int ans = 0;
    int u,d,bad;
    vpi gr;
    
    gr = vpi(n, mp(-1,-1));
    u = 0;
    d = 0;
    for(int i = n-1; i>=imax; i--) {
        if(a[i] > u) u = a[i];
        else if(a[i] > d) d = a[i];
        else {
            break;
        }
        gr[i] = mp(u, d);
    }
    r = a;
    for(int i = n-2; i>=0; i--) r[i] = max(r[i], r[i+1]);
    u = 0;
    d = 0;
    bad = 0;
    forn(i,0,imax+1) {
        if(a[i] > u) u = a[i];
        else if(a[i] > d) d = a[i];
        else {
            bad = 1;
            break;
        }
    }
    if(bad == 0) {
        forn(i,imax+1,n) {
//            if(gr[i].first == -1) break;
            if(gr[i].first != -1 && d < a[i]) {
                int cu = a[i];
                int cd = u;
                if(cu < cd) swap(cu, cd);
                if(cu >= gr[i].first && cd >= gr[i].second) ans++;
            }
//            if(a[i] == r[i] && d < a[i] && u > gr[i].second) ans++;
            if(i+1==n) break;
            if(a[i] > a[i+1]) {
                if(u > a[i]) u = a[i];
                else if(d < a[i]) d = a[i];
                else break;
            }
            else {
                if(d < a[i]) d = a[i];
                else if(u > a[i]) u = a[i];
                else break;
            }
        }
    }
    
    reverse(all(a));
    imax = n-1-imax;
    
    gr = vpi(n, mp(-1,-1));
    u = 0;
    d = 0;
    for(int i = n-1; i>=imax; i--) {
        if(a[i] > u) u = a[i];
        else if(a[i] > d) d = a[i];
        else {
            break;
        }
        gr[i] = mp(u, d);
    }
    r = a;
    for(int i = n-2; i>=0; i--) r[i] = max(r[i], r[i+1]);
    u = 0;
    d = 0;
    bad = 0;
    forn(i,0,imax+1) {
        if(a[i] > u) u = a[i];
        else if(a[i] > d) d = a[i];
        else {
            bad = 1;
            break;
        }
    }
    if(bad == 0) {
        forn(i,imax+1,n) {
//            if(gr[i].first == -1) break;
            if(gr[i].first != -1 && d < a[i]) {
                int cu = a[i];
                int cd = u;
                if(cu < cd) swap(cu, cd);
                if(cu >= gr[i].first && cd >= gr[i].second) ans++;
            }
            //            if(a[i] == r[i] && d < a[i] && u > gr[i].second) ans++;
            if(i+1==n) break;
            if(a[i] > a[i+1]) {
                if(u > a[i]) u = a[i];
                else if(d < a[i]) d = a[i];
                else break;
            }
            else {
                if(d < a[i]) d = a[i];
                else if(u > a[i]) u = a[i];
                else break;
            }
        }
    }
    
    cout<<ans;
    
    
}