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

vector<int> z_function(string const& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int sin(string s, string t) {
    if(s==t) return s.size() - 1;
    auto zf = z_function(s+"#"+t);
    forn(i,0,zf.size()) if(zf[i]==s.size()) return i - s.size() - 1;
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vs a,b;
    char c[5050];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    forn(i,0,n) {
        scanf("%s", c);
        b.pb(string(c));
    }
    vpi lr;
    string f,to;
    forn(i,0,n) {
        if(a[i] == b[i]) lr.pb(mp(-1,-1));
        else {
            int l = 0;
            while(a[i][l] == b[i][l]) l++;
            int r = a[i].size() - 1;
            while(a[i][r] == b[i][r]) r--;
            string curf = a[i].substr(l,r-l+1);
            string curto = b[i].substr(l,r-l+1);
            if(!f.empty()) {
                if(curf != f || curto != to) {
                    printf("NO\n");
                    exit(0);
                }
            }
            else {
                f = curf;
                to = curto;
            }
            lr.pb(mp(l,r));
        }
    }
    if(f.empty()) {
        printf("YES\n");
        printf("yes\n");
        printf("yes\n");
        exit(0);
    }
    while(1) {
        char al = '*';
        char ar = '*';
        int canl = 1;
        int canr = 1;
        forn(i,0,n) {
            if(lr[i].first == -1) continue;
            if(lr[i].first == 0) {
                canl = 0;
            }
            else if(al != '*' && a[i][lr[i].first-1] != al) {
                canl = 0;
            }
            else al = a[i][lr[i].first-1];
            
            if(lr[i].second == a[i].size() - 1) {
                canr = 0;
            }
            else if(ar != '*' && a[i][lr[i].second+1] != ar) {
                canr = 0;
            }
            else ar = a[i][lr[i].second+1];
        }
        if(canl + canr == 0) break;
        forn(i,0,n) {
            if(lr[i].first == -1) continue;
            lr[i].first -= canl;
            lr[i].second+=canr;
        }
    }
    int pt  = 0;
    while(lr[pt].first == -1) pt++;
    f = a[pt].substr(lr[pt].first,lr[pt].second-lr[pt].first+1);
    to = b[pt].substr(lr[pt].first,lr[pt].second-lr[pt].first+1);
    forn(i,0,n) {
        if(lr[i].first == -1 && sin(f, a[i])!=-1) {
            printf("NO\n");
            exit(0);
        }
        if(lr[i].first != -1 && sin(f,a[i]) < lr[i].first) {
            printf("NO\n");
            exit(0);
        }
    }
    printf("YES\n");
    printf("%s\n", f.c_str());
    printf("%s\n", to.c_str());
    
    
}