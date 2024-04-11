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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    srt(a);
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    int l = 20;
    while(1) {
        l--;
        int cur = 0;
        int pr = 0;
        forn(i,0,n-1) {
            while(cur + d2[l] <= a[i]) cur+=d2[l];
            if(a[i+1] < cur + d2[l]) {
                pr = 1;
                break;
            }
        }
        if(pr == 0) {
            l ++;
            break;
        }
    }
    vvi ans(k+1, vi(d2[k], d2[k]));
    int s = 0;
    forn(i,0,n-1) {
        while(s + d2[l] <= a[i]) s+=d2[l];
        if(a[i+1] < s + d2[l]) {
            forn(x,0,d2[l]) ans[l][x] = min(ans[l][x], abs((a[i]^x) - (a[i+1]^x)));
        }
    }
    vvi h(d2[k-l]);
    forn(i,0,n) h[a[i]/d2[l]].pb(a[i]);
    forn(i,0,n) {
        int curst = a[i] / d2[l];
        forn(j,1,k-l+1) {
            int altst = curst ^ (d2[j] - 1);
            int xst1 = (curst & (d2[j] - 1)) ^ d2[j-1];
            int xst2 = (xst1 & (d2[j] - 1));
            xst1 *= d2[l];
            xst2 *= d2[l];
            for(auto b : h[altst]) {
                forn(x, 0, d2[l]) {
                    int x1 = xst1 + x;
                    int x2 = xst2 + x;
                    ans[l+j][x1] = min(ans[l+j][x1], abs((a[i]^x1) - (b^x1)));
                    ans[l+j][x2] = min(ans[l+j][x2], abs((a[i]^x2) - (b^x2)));
                }
            }
        }
    }
    forn(i,0,k) forn(x,0,d2[i]) {
        ans[i+1][x] = min(ans[i+1][x], ans[i][x]);
        ans[i+1][x+d2[i]] = min(ans[i+1][x+d2[i]], ans[i][x]);
    }
    forn(i,0,d2[k]) printf("%d ", ans[k][i]);
}