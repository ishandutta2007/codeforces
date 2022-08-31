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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        read(n);
        readv(a,n);
        readv(b,n);
        vpi ans;
        auto flip = [&](int l, int r) {
            ans.pb(mp(l+1, r+1));
            forn(i,l,r+1) if(i < r+l-i) swap(a[i], a[r+l-i]);
        };
        
        vpi ap, bp;
        forn(i,0,n-1) {
            ap.pb(mp(min(a[i],a[i+1]), max(a[i],a[i+1])));
            bp.pb(mp(min(b[i],b[i+1]), max(b[i],b[i+1])));
        }
        srt(ap);
        srt(bp);
        if(ap != bp || a[0] != b[0] || a.back() != b.back()) {
            printf("NO\n");
            continue;
        }
        int can = 1;
        forn(i,1,n-1) {
            if(a[i] != b[i]) {
                forn(j,i,n-1) {
                    if(a[j] == b[i] && a[j+1] == b[i-1]) {
                        flip(i-1, j+1);
                        break;
                    }
                }
            }
            if(a[i] != b[i]) {
                int win = 0;
                forn(l,i-1,n-1) {
                    int hit = 0;
                    forn(r,l+1,n) {
                        if(a[r] == b[i] && a[r-1] == b[i-1]) {
                            hit = 1;
                        }
                        if(a[r] == a[l] && hit) {
                            win = 1;
                            flip(l, r);
                            break;
                        }
                    }
                    if(win) break;
                }
                if(win) {
                    forn(j,i,n-1) {
                        if(a[j] == b[i] && a[j+1] == b[i-1]) {
                            flip(i-1, j+1);
                            break;
                        }
                    }
                }
                else {
                    can = 0;
                    break;
                }
            }
        }
        if(can) {
            printf("YES\n");
            printf("%d\n", ans.size());
            for(auto x : ans) printf("%d %d\n", x.first, x.second);
        }
        else printf("NO\n");
        
    }
    
    
}