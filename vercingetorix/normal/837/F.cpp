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
typedef vector<vvll> vvvll;
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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
ll kl;
bool flag = false;
int n;
vll a;

vvll mprod(vvll &a, vvll &b) {;
    vvll c(n, vll(n,0));
    forn(i,0,n) {
        forn(j,0,n) {
            forn(k,0,n) {
                if(b[k][j] > 0 && a[i][k] > kl/b[k][j]) flag = true;
                c[i][j] = c[i][j] +a[i][k] * b[k][j];
                if(c[i][j] >= kl) flag = true;
            }
        }
    }
    return c;
}
void print(vvll & x) {
    forn(i,0,n) {
        forn(j,0,n) {
            cout<<x[i][j] <<' ';
            
        }
        cout<<endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %lld", &n, &kl);
    
    bool can = false;
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        if(x >= kl) {
            cout<<0;
            return 0;
        }
        if(x>0) can = true;
        if(can) a.pb(x);
    }
    n = a.size();
    if(n > 10) {
        int it = 0;
        while(1) {
            it++;
            ll sum = 0;
            forn(i,0,n) {
                sum += a[i];
                if(sum >= kl) {
                    cout<<it;
                    return 0;
                }
                a[i] = sum;
            }
        }
    }
    vvvll d(1, vvll(n, vll(n, 0)));
    forn(i,0,n) forn(j,0,i+1) d[0][i][j] = 1;
    while(!flag) d.pb(mprod(d.back(), d.back()));
    d.pop_back();
    ll ans = 0;
    vvll mcur(n, vll(n,0));
    forn(i,0,n) mcur[i][i] = 1;
    for(int bit = (int)d.size() - 1; bit >= 0; bit--) {
        flag = false;
        vvll mnew = mprod(mcur, d[bit]);
        if(flag) continue;
        ll res = 0;
        forn(i,0,n) {
            if(a[i] > 0 && mnew[n-1][i] > kl/a[i]) flag = true;
            res += mnew[n-1][i] * a[i];
            if(res >= kl) flag = true;
        }
        if(flag) continue;
        ans += 1ll<<bit;
        mcur = mnew;
    }
    cout<<ans+1;
    
    
}