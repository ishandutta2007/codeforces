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

vi l(26,-1);
vi r(26,-1);

bool canadd(int a, int b) {
    if(l[a] != -1 && l[a] != b) return false;
    if(r[b] != -1 && r[b] != a) return false;
    return true;
}

bool add(int a, int b) {
    if(l[a] != -1 && l[a] != b) return false;
    if(r[b] != -1 && r[b] != a) return false;
    l[a] = b;
    r[b] = a;
    return true;
}
int k;
void yes() {
    vi fa,fb;
    forn(i,0,k) {
        if(l[i] == -1) fa.pb(i);
        if(r[i] == -1) fb.pb(i);
    }
    forn(i,0,fa.size()) l[fa[i]] = fb[i];
    string ans;
    forn(i,0,k) ans.pb(char('a' + l[i]));
    printf("YES\n");
    printf("%s\n", ans.c_str());
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    char c[1000500];
    forn(ifa,0,ta) {
        
        scanf("%d\n", &k);
        scanf("%s", c);
        string ss(c);
        vi s,a,b;
        int n = ss.size();
        forn(i,0,n) s.pb(c[i]-'a');
        scanf("%s", c);
        forn(i,0,n) a.pb(c[i]-'a');
        scanf("%s", c);
        forn(i,0,n) b.pb(c[i]-'a');
        int done = 0;
        int fall = 0;
        int bad = 0;
        forn(i,0,k) {
            l[i] = -1;
            r[i] = -1;
        }
        forn(i,0,n) {
            if(done) break;
            if(fall) {
                forn(j,a[i] + 1,k) {
                    if(canadd(s[i], j)) {
                        done = 1;
                        add(s[i], j);
                        yes();
                        break;
                    }
                }
            }
            else {
                if(b[i] > a[i]) {
                    forn(j,a[i]+1,b[i]) {
                        if(canadd(s[i], j)) {
                            done = 1;
                            add(s[i], j);
                            yes();
                            break;
                        }
                    }
                    fall = 1;
                }
            }
            if(!add(s[i], a[i])) {
                bad = 1;
                break;
            }
        }
        if(bad == 0 && done == 0) {
            yes();
            done = 1;
        }
        fall = 0;
        bad = 0;
        forn(i,0,k) {
            l[i] = -1;
            r[i] = -1;
        }
        forn(i,0,n) {
            if(done) break;
            if(fall) {
                forn(j,0,b[i]) {
                    if(canadd(s[i], j)) {
                        done = 1;
                        add(s[i], j);
                        yes();
                        break;
                    }
                }
            }
            else {
                if(b[i] > a[i]) {
                    forn(j,a[i]+1,b[i]) {
                        if(canadd(s[i], j)) {
                            done = 1;
                            add(s[i], j);
                            yes();
                            break;
                        }
                    }
                    fall = 1;
                }
            }
            if(!add(s[i], b[i])) {
                bad = 1;
                break;
            }
        }
        if(bad == 0 && done == 0) {
            yes();
            done = 1;
        }
        if(!done) printf("NO\n");
    }
    
    
}