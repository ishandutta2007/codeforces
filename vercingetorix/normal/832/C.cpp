#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<ld> vld;
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,si;
    scanf("%d %d", &n, &si);
    ld s = si;
    vld x(n), v(n);
    vi dir(n);
    vector<pair<pi, int>> ev;
    ld EPS = 1e-8;
    forn(i,0,n) {
        int xi, vi;
        scanf("%d %d %d", &xi, &vi, &dir[i]);
        ev.pb(mp(mp(xi, dir[i]), vi));
        x[i] = xi;
        v[i] = vi;
    }
    sort(all(ev));
    ld l = 0;
    ld A = 1000000;
    ld r = A;
    ld m0=1e7, m1=1e7;
    ld m0s=1e7, m1s=1e7;
    forn(i,0,n) {
        if(dir[i] == 1) {
            m0=min(m0, x[i] / v[i]);
            m0s=min(m0s, x[i] / (s+v[i]));
        }
        else {
            m1=min(m1, (A-x[i]) / v[i]);
            m1s=min(m1s, (A-x[i]) / (s+v[i]));
        }
    }
    forn(it,0,50) {
        ld m = (l+r)/2;

        if(m0s > m || m1s > m) {
            l = m;
            continue;
        }
        if (m0 <= m+EPS) {
            if (m1s <= m) r = m;
            else l = m;
            continue;
        }
        if (m1 <= m+EPS) {
            if (m0s <= m) r = m;
            else l = m;
            continue;
        }
        bool can = false;
        ld maxr = -1e18;
        for(auto x : ev) {
            if(x.first.second == 1) {
                ld d = x.first.first;
                ld v = x.second;
                if((v+s)*m < d+EPS) continue;
                ld u = (m*(v+s) - d);
                maxr = floor(EPS+max(maxr, EPS+d + (1-v/s)*u));
            }
            else {
                ld d = A-x.first.first;
                ld v = x.second;
                if((v+s)*m  < d+EPS) continue;
                ld u = (m*(v+s) - d);
                if(maxr + (1-v/s)*u >= x.first.first) {
                    can = true;
                    break;
                }
            }
        }
        if(can) r = m;
        else l = m;
    }
    printf("%.10lf", (double)l);
    
}