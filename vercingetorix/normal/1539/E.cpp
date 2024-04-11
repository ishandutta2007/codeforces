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
typedef std::vector<vvi> vvvi;
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
    int n,m;
    scanf("%d %d", &n, &m);
//    readv(a,n);
    vi a(n);
    vvi pl(2, vi(n)), pr(2, vi(n));
    forn(i,0,n) {
        scanf("%d", &a[i]);
        forn(j,0,2) scanf("%d %d", &pl[j][i], &pr[j][i]);
    }
    vvi mt(2, vi(n, 0));
    vvpi mxl(2);
    vvpi mnr(2);
    forn(j,0,2) {
        mxl[j].pb(mp(2e9, n));
        mnr[j].pb(mp(-1, n));
    }
    vvi works(2, vi(n, -1));
    forn(j,0,2) {
        for(int i = n-1; i>=0; i--) {
            while(mxl[j].back().first <= pl[j][i]) mxl[j].pop_back();
            mxl[j].pb(mp(pl[j][i], i));
            while(mnr[j].back().first >= pr[j][i]) mnr[j].pop_back();
            mnr[j].pb(mp(pr[j][i], i));
            int l = 0;
            int r = mxl[j].size();
            while(r-l > 1) {
                int m = (r+l)/2;
                if(mxl[j][m].first <= a[i]) r = m;
                else l = m;
            }
            works[j][i] = mxl[j][l].second - 1;
            l = 0;
            r = mnr[j].size();
            while(r-l > 1) {
                int m = (r+l)/2;
                if(mnr[j][m].first >= a[i]) r = m;
                else l = m;
            }
            works[j][i] = min(mnr[j][l].second - 1, works[j][i]);
        }
    }
    vvvi cards(n);
    vvi p(n);
    vvvi prevcard(n);
    forn(j,0,2) {
        int w0 = 0;
        while(w0 < n && pl[1-j][w0] == 0) w0+=1;
        vi res(2);
        res[j] = works[j][0];
        res[1-j] = w0-1;
        if(res[0] >= 0 && res[1] >= 0) {
            cards[0].pb(res);
            p[0].pb(j);
            prevcard[0].pb(res);
        }
    }
    forn(i,1,n) {
        forn(j,0,2) {
            vi ncard(2, i-1);
            if(works[j][i] < i) continue;
            ncard[j] = works[j][i];
            vi npcard;
            forn(r,0, p[i-1].size()) {
                if(cards[i-1][r][1-j] > ncard[1-j]) {
                    ncard[1-j] = cards[i-1][r][1-j];
                    npcard = cards[i-1][r];
                }
            }
            if(ncard[1-j] > i-1) {
                cards[i].pb(ncard);
                p[i].pb(j);
                prevcard[i].pb(npcard);
            }
        }
    }
    if(cards[n-1].empty()) {
        cout<<"No";
    }
    else {
        cout<<"Yes\n";
        vi ans;
        vi curcard = cards[n-1][0];
        for(int i = n-1; i>=0; i--) {
            forn(r,0,cards[i].size()) {
                if(cards[i][r] == curcard) {
                    ans.pb(p[i][r]);
                    curcard = prevcard[i][r];
                    break;
                }
            }
        }
        reverse(all(ans));
        for(auto x : ans)printf("%d ", x);
    }
//    forn(i,0,n)
//    forn(i,0,n) {
//        printf("%d %d\n", works[0][i], works[1][i]);
//    }
//
}