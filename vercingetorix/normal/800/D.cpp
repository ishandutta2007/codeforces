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
const int A = 1000000;

void proc(vll & a) {
    
}
int st[64][6];
ll sumy[A];
ll sumy2[A];
ll ans[A];
ll cnt[A];
char xinc[1000000][64];
int go[64];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    vi sgn(64,-1);
    forn(i,0,64) {
        int x = i;
        int d10 = 1;
        while(x>0) {
            if(x%2) {
                go[i] += d10;
                sgn[i] = -sgn[i];
            }
            d10*=10;
            x/=2;
        }
    }
    forn(i,0,64) {
        int x = i;
        for(int j = 5; j>=0; j--) {
            st[i][j] = x%2;
            x /= 2;
        }
    }
    forn(i,0,A) {
        vi dig(6);
        int x = i;
        for(int j = 5; j>=0; j--) {
            dig[j] = x%10;
            x /= 10;
        }
        forn(inc,1,64) {
            int was = 0;
            bool bad = false;
            forn(j,0,6) {
                int nd = dig[j] + st[inc][j];
                if(nd > 9) bad = true;
                was = was*10 + nd;
            }
            if(bad) xinc[i][inc] = -1;
            else xinc[i][inc] = 1;
        }
    }
    
    int n;
    scanf("%d", &n);
    int x;
    forn(i,0,n) {
        scanf("%d", &x);
        cnt[x]++;
    }
    forn(i,0,A) {
        sumy[i] = (cnt[i] * (ll) i)%mod;
        sumy2[i] = (sumy[i] * (ll)i)%mod;
    }
    vll d2(1,1);
    forn(i,0,A+10) d2.pb((d2.back()*2)%mod);
    for(int i = A-1; i>=0; i--) {
        forn(inc,1,64) {
            if(xinc[i][inc] == -1) continue;
            int was = i + go[inc];
            cnt[i] += cnt[was] * sgn[inc];
            sumy[i] += sumy[was] * sgn[inc];
            sumy2[i] += sumy2[was] * sgn[inc];
        }
        cnt[i] = (mod + cnt[i] % mod) % mod;
        sumy[i] = (mod + sumy[i] % mod) % mod;
        sumy2[i] = (mod + sumy2[i] % mod) % mod;
        if(cnt[i] == 0) ans[i] = 0;
        else if(cnt[i] == 1) ans[i] = sumy2[i];
        else {
            ans[i] = (sumy[i]*sumy[i]+sumy2[i])%mod;
            ans[i] = (ans[i] * d2[cnt[i]-2]) % mod;
        }
    }
    for(int i = 0; i<A; i++) {
        forn(inc,1,64) {
            if(xinc[i][inc] == -1) continue;
            int was = i + go[inc];
            ans[i] = (mod + ans[i] - ans[was] * sgn[inc]) % mod;
        }
    }
    ll res = 0;
    forn(i,0,A) {
        res = res ^ (i * ans[i]);
    }
    cout << res;
    
}