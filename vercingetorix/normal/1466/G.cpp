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
typedef std::vector<vpll> vvpll;

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

vector<int> zf (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int kin(string s, string t) {
    vi x = zf(t+"#"+s);
    int ret = 0;
    forn(i, t.size() + 1, t.size() + 1 + s.size()) if(x[i] == t.size()) ret++;
    return ret;
}
int i2pref[26][1000500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d\n", &n, &q);
    char c0[1000];
    scanf("%s", c0);
    vs s;
    s.pb(string (c0));
    char t[100500];
    scanf("%s", t);
    int pt = 0;
    while(s.back().size() < 1000000 && pt<n) {
        s.pb(s.back() + string(1,t[pt++]) + s.back());
    }
    vll d2(1,1);
    vll di2(1,1);
    ll i2 = (mod+1)/2;
    forn(i,0,100500) d2.pb(d2.back()*2%mod);
    forn(i,0,100500) di2.pb(di2.back()*i2%mod);
    forn(i,0,n) {
        forn(j,0,26) i2pref[j][i+1] = i2pref[j][i];
        i2pref[t[i]-'a'][i+1] = (i2pref[t[i]-'a'][i+1]+di2[i+1])%mod;
    }
    
    char cname[1005000];
    while(q--) {
        int k;
        scanf("%d %s", &k, cname);
        string name(cname);
        int l = name.size();
        int pt = 0;
        while(s[pt].size() < name.size() && pt < k) pt++;
        ll kind = kin(s[pt], name);
        ll cur = kind*d2[k-pt]%mod;
        if(k>pt) {
            forn(j,0,26) {
                ll inc = kin(s[pt].substr(s[pt].size() - name.size()+1) + string(1, 'a'+j) + s[pt].substr(0, name.size()-1), name);
                ll cnt = d2[k] * (mod+i2pref[j][k] - i2pref[j][pt])%mod;
                cur = (cur + inc * cnt) % mod;
            }
        }
        printf("%lld\n", cur);
    }
    
}