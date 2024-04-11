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
int n;
vi a, sd;
int ans = 0;
void imdone() {
    printf("-1\n");
    exit(0);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    a= vi(2*n);
    sd = vi(2*n);
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--; y--;
        a[x] = y;
        a[y] = x;
        sd[x] = 0;
        sd[y] = 1;
    }
    int l = 0;
    int r = 2*n-1;
    vi used(2*n,0);
    while(l <= r) {
        vpi ql, qr;
        ql.pb(mp(l, a[l]));
        int ml = l;
        int mr = a[l];
        used[l] = 1;
        used[a[l]] = 1;
        int pl = l;
        int pr = r;
        while(pl < ml or pr > mr) {
            while(pl < ml) {
                if(used[pl] == 0) {
                    int d = a[pl];
                    if(d <= ml) imdone();
                    ql.pb(mp(pl, d));
                    used[pl] = 1;
                    used[d] = 1;
                    mr = min(mr, d);
                }
                pl++;
            }
            while(pr > mr) {
                if(used[pr] == 0) {
                    int d = a[pr];
                    if(d >= mr) imdone();
                    qr.pb(mp(pr, d));
                    used[pr] = 1;
                    used[d] = 1;
                    ml = max(ml, d);
                }
                pr--;
            }
        }
        forn(i,1,ql.size()) if(ql[i].second > ql[i-1].second) imdone();
        forn(i,1,qr.size()) if(qr[i].second < qr[i-1].second) imdone();
        l = ml+1;
        r = mr-1;
        vi cnt(2,0);
        for(auto x : ql) cnt[sd[x.first]]++;
        for(auto x : qr) cnt[sd[x.first]]++;
        ans += min(cnt[0], cnt[1]);
    }
    cout<<ans;
    
}