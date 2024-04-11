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
typedef pair<ld,int> pldi;
typedef std::vector<ld> vld;
typedef std::vector<pldi> vpldi;
typedef std::vector<vld> vvld;
typedef std::vector<vpldi> vvpldi;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const ld INF = 1e12;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    vld p(n), u(n);
    double x;
    forn(i,0,n) {
        scanf("%lf", &x);
        p[i] = x;
    }
    forn(i,0,n) {
        scanf("%lf", &x);
        u[i] = x;
    }
    ld l1 = 0;
    ld r1 = n;
    int cnt1 = 0;
    ld eps = 1e-12;
    while(1) {
        ld ma = (l1+r1)/2;
        ld l = 0;
        ld r = n;
        int cnt = 0;
        vector<pair<ld, pi>> d;
        while(1) {
            ld m = (l+r)/2;
            d = vector<pair<ld, pi>>(n+1, mp(-INF, mp(0,0)));
            d[0] = mp(0, mp(0,0));
            forn(i,0,n) {
                ld ob = u[i] - m;
                ld oa = p[i] - ma;
                ld ab = u[i] + p[i] - u[i]*p[i] - m - ma;
                int ca = d[i].second.first;
                int cb = d[i].second.second;
                d[i+1] = max(d[i+1], d[i]);
                d[i+1] = max(d[i+1], mp(d[i].first + oa, mp(ca+1,cb)));
                d[i+1] = max(d[i+1], mp(d[i].first + ob, mp(ca,cb+1)));
                d[i+1] = max(d[i+1], mp(d[i].first + ab, mp(ca+1,cb+1)));
            }
            if(d[n].second.second == b || cnt == 50) {
                l = m;
                break;
            }
            if(d[n].second.second > b) l=m;
            else r=m;
            cnt++;
        }
        if(d[n].second.first == a || cnt1 == 50) {
            printf("%.10lf", (double)(d[n].first + ma*a + l*b));
            return 0;
        }
        if(d[n].second.first > a) l1=ma;
        else r1=ma;
        cnt1++;
    }
    
}