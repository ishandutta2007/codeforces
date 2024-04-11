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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,c;
    scanf("%d %d", &n, &c);
    vi p(n);
    vi s(n);
    forn(i,0,n) scanf("%d", &p[i]);
    forn(i,0,n) scanf("%d", &s[i]);
    deque<int> f;
    const int INF = 1e9 + 791;
    ll ans = 0;
    forn(i,0,n) {
        while(!f.empty() && f.back() ==0) f.pop_back();
        int cur = p[i] - s[i];
        
        int l = 0;
        int r = 0;
        int low = INF;
        while(1) {
            int nl1 = -INF;
            int nl2 = -INF;
            if(r>l) nl1 = f[l]-c;
            if(r<f.size()) nl2 = f[r];
            int step = (low-cur)/(r-l+1);
            int nl3 = low - step;
            int nl = max(nl1,nl2);
            nl = max(nl, nl3);
            nl = max(nl,0);
            if(nl == low) {
                if(low == 0) {
                    forn(j,l,r) f[j] = 0;
                    break;
                }
//                low-cur <= r-l
                int prev = low;
                if(cur < low) {
                    prev = low-1;
                    int dec = low - 1 - cur;
                    int left = r-l - dec;
                    forn(j,l,l+left) {
                        f[j] = low;
                    }
                    forn(j,l+left,r) {
                        f[j] = low-1;
                    }
                }
                else {
                    forn(j,l,r) f[j] = low;
                }
                cur = prev;
                forn(j,r,f.size()) {
                    swap(prev,f[j]);
                }
                f.pb(prev);
                break;
            }
            else {
                cur += (r-l)*(low-nl);
                low = nl;
                while(r<f.size() && f[r] == low) r++;
                while(l<r && f[l] == low + c) {
                    f[l] -= c;
                    l++;
                }
            }
            
        }
        
        ans += s[i];
        if (cur < 0) ans += cur;
    }
    printf("%lld\n", ans);
}