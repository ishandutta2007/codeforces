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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll tp[4][4][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vi x(n), y(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    ll ans = 0;
    forn(r1,0,2) forn(r2,0,2) {
        vvi cnt(2, vi(2,0));
        int tot = 0;
        forn(i,0,n) if(x[i]%2 == r1 && y[i]%2==r2) {
            cnt[(x[i]/2)%2][(y[i]/2)%2]++;
            tot++;
        }
        forn(i,0,2) forn(j,0,2) {
            ll k = cnt[i][j];
            ans += k*(k-1)*(k-2)/6;
            ans += k*(k-1)/2 * (tot-k);
        }
    }
    ans*=2;
    forn(i,0,n) {
        int r1 = x[i]%2;
        int r2 = y[i]%2;
        forn(t1,0,4) forn(t2,0,4) forn(t3,0,4) tp[t1][t2][t3] = 0;
        forn(j,0,n) {
            if(x[i]%2==x[j]%2 && y[i]%2==y[j]%2) continue;
            int d = gcd(abs(x[i]-x[j]), abs(y[i]-y[j]));
            tp[x[j]%4][y[j]%4][(d/2)%2]++;
        }
        forn(rx1,0,4) forn(rx2,0,4) forn(ry1,0,4) forn(ry2,0,4) forn(d1,0,2) forn(d2,0,2) {
            if(rx1%2 != rx2 %2) continue;
            if(ry1%2 != ry2 %2) continue;
            int b12 = 0;
            if(d1 != d2) b12 = 1;
            int bd = 0;
            if((rx1+rx2)/2%2 == r1 && (ry1+ry2)/2%2 == r2) bd = 1;
            if(b12 + bd == 1) {
                if(rx1==rx2 && ry1 == ry2 && d1 == d2) {
                    ans += tp[rx1][ry1][d1] * (tp[rx1][ry1][d1]-1);
                }
                else ans += tp[rx1][ry1][d1] * tp[rx2][ry2][d2];
            }
        }
    }
    cout<<ans/2;
    
}