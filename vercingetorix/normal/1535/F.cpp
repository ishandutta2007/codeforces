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
int cnt[26];

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}
const int A = 300;
ll dp1[A];
ll kdp1[26][A];
ll kdp1deg[26][A][A];
ll idp1[A];
ll dq1[A];
ll kdq1[26][A];
ll kdq1deg[26][A][A];
ll idq1[A];

ll p1 = 463;
ll p2 = 1030005037;

ll q1 = 239;
ll q2 = 1003000027;

ll hasha(string & s) {
    ll h = 0;
    ll h2 = 0;
    for(auto x : s) {
        h = (h*p1+int(x-'a'))%p2;
        h2 = (h2*q1+int(x-'a'))%q2;
    }
    return h + h2*p2;
}

vll ah2,ah;
int pt = 0;

void build_all(const string & s) {
    ah2.clear();
    ah.clear();
    int n = s.size();
    ll pref = 0;
    ll pref2 = 0;
    forn(l,0,n) {
        forn(k,0,26) cnt[k] = 0;
        int r = l;
        while(r < n) {
            cnt[s[r++] - 'a']++;
        }
        ll suf = 0;
        ll suf2 = 0;
        int sdeg = 0;
        while(r > l) {
            int deg = sdeg;
            ll cur = suf;
            ll cur2 = suf2;
            for(int i = 25; i>=0; i--) if(cnt[i]){
                cur += kdp1deg[i][cnt[i]][deg];
                cur2 += kdq1deg[i][cnt[i]][deg];
                deg += cnt[i];
            }
            ah2.pb((pref + cur)%p2 + p2*((pref2 + cur2)%q2));
            r--;
            cnt[s[r] - 'a'] --;
            suf = (suf + int(s[r]-'a')*dp1[sdeg])%p2;
            suf2 = (suf2 + int(s[r]-'a')*dq1[sdeg])%q2;
            sdeg++;
        }
        pref = (pref + dp1[n-1-l]*int(s[l]-'a'))%p2;
        pref2 = (pref2 + dq1[n-1-l]*int(s[l]-'a'))%q2;
    }
    srt(ah2);
    forn(i,0,ah2.size()) if(i==0 || ah2[i] != ah2[i-1]) ah.pb(ah2[i]);
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    dp1[0] = 1;
    forn(i,1,A) dp1[i] = dp1[i-1]*p1%p2;
    forn(i,0,A) idp1[i] = invmod(dp1[i], p2);
    kdp1[1][0] = 0;
    forn(i,1,A) {
        kdp1[1][i] = (kdp1[1][i-1] + dp1[i-1])%p2;
    }
    forn(i,0,A) forn(j,0,26) kdp1[j][i] = kdp1[1][i] * j % p2;
    forn(i,0,A) forn(j,0,26) forn(deg,0,A) kdp1deg[j][i][deg] = kdp1[j][i]*dp1[deg]%p2;
    
    dq1[0] = 1;
    forn(i,1,A) dq1[i] = dq1[i-1]*q1%q2;
    forn(i,0,A) idq1[i] = invmod(dq1[i], q2);
    kdq1[1][0] = 0;
    forn(i,1,A) {
        kdq1[1][i] = (kdq1[1][i-1] + dq1[i-1])%q2;
    }
    forn(i,0,A) forn(j,0,26) kdq1[j][i] = kdq1[1][i] * j % q2;
    forn(i,0,A) forn(j,0,26) forn(deg,0,A) kdq1deg[j][i][deg] = kdq1[j][i]*dq1[deg]%q2;
    
    int n;
    scanf("%d\n", &n);
    vs s;
    char c[200500];
    forn(i,0,n) {
        scanf("%s", c);
        s.pb(string(c));
    }
    map<string, vi> x;
    int m = s[0].size();
    ll ans = 0;
    if (n<=4000) {
        forn(i,0,n) forn(j,i+1,n) {
            forn(k,0,26) cnt[k] = 0;
            int l = 0;
            int r = m-1;
            while(l<m && s[i][l] == s[j][l]) l++;
            while(r>=0 && s[i][r] == s[j][r]) r--;
            if(r>=l) {
                forn(k,l,r+1) {
                    cnt[s[i][k]-'a']++;
                    cnt[s[j][k]-'a']--;
                }
                int can = 1;
                forn(k,0,26) {
                    if(cnt[k] != 0) can = 0;
                }
                if(can == 0) {
                    ans += 1337;
                    continue;
                }
                int si = 1, sj = 1;
                forn(k,l,r) {
                    if(s[i][k] > s[i][k+1]) si = 0;
                    if(s[j][k] > s[j][k+1]) sj = 0;
                }
                if(si || sj) ans ++;
                else ans += 2;
            }
        }
        cout<<ans;
    }
    else {
        unordered_map<ll, int> ha;
        for(auto & x : s) ha[hasha(x)]++;
        ll p0 = 0;
        ll p1 = 0;
        for(auto & x : s) {
            build_all(x);
            p0 += ha[hasha(x)] - 1;
            for(auto y : ah) p1 += ha[y];
        }
        ll p2 = 0;
        ll p1337 = ll(n)*(n-1)/2;
        unordered_map<ll, int> ha2;
        forn(i,0,n) {
            string t = s[i];
            srt(t);
            ll ht = hasha(t);
            p2 += ha2[ht];
            ha2[ht]++;
        }
        p0 /= 2;
        p1 -= n+2*p0;
        p2 -= p1+p0;
        p1337 -= p0+p1+p2;
        cout<<p1+2*p2+1337*p1337;
    }
    
    
    
    
}