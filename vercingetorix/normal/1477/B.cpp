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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

set<pair<pi, int>> a;
char c1[200100], c2[200100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    
    while(t--) {
        a.clear();
        int n,q;
        scanf("%d %d\n", &n, &q);
        scanf("%s", c1);
        scanf("%s", c2);
        string s(c1);
        string f(c2);
        int pt = 0;
        while(pt < n) {
            int ptr = pt+1;
            while(ptr<n && f[ptr] == f[pt]) ptr++;
            a.insert(mp(mp(pt, ptr-1), int(f[pt]-'0')));
            pt = ptr;
        }
        vi l(q), r(q);
        forn(i,0,q) scanf("%d %d", &l[i], &r[i]);
        reverse(all(l));
        reverse(all(r));
        int bad = 0;
        forn(i,0,q) {
            l[i]--; r[i]--;
            auto it = a.lower_bound(mp(mp(l[i]+1, 0), 0));
            it--;
            vector<pair<pi, int>> todel;
            while(it != a.end() && (it->first.second >= l[i] && it->first.first <= r[i])) {
                todel.pb(*it);
                it++;
            }
            vi cnt(2,0);
            for(auto x : todel) {
                int cl = max(l[i], x.first.first);
                int cr = min(r[i], x.first.second);
                cnt[x.second] += cr-cl+1;
                a.erase(x);
                if(x.first.first < l[i]) {
                    a.insert(mp(mp(x.first.first, l[i]-1), x.second));
                }
                if(x.first.second > r[i]) {
                    a.insert(mp(mp(r[i]+1, x.first.second), x.second));
                }
            }
            if(cnt[0] == cnt[1]) {
                bad = 1;
                break;
            }
            else {
                int sym = 0;
                if(cnt[1] > cnt[0]) sym = 1;
                a.insert(mp(mp(l[i], r[i]), sym));
            }
        }
        if(bad) printf("NO\n");
        else {
            f.clear();
            for(auto x : a) {
                forn(i,0,x.first.second-x.first.first+1) f.pb('0' + x.second);
            }
            if(f==s) printf("YES\n");
            else printf("NO\n");
        }
    }
    
}