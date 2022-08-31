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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi inv(5);
    inv[1] = 1;
    inv[2] = 3;
    inv[3] = 2;
    inv[4] = 4;
    int n,m;
    scanf("%d %d\n", &n, &m);
    char c[501];
    vvi a(n);
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,m) {
            a[i].pb(c[j]-'a');
        }
    }
    int cs = 0;
    vi mean;
    forn(col,0,m) {
        bool has = false;
        forn(i,cs,n) {
            if(a[i][col] != 0) {
                has = true;
                swap(a[cs], a[i]);
                break;
            }
        }
        if(!has) continue;
        int la = inv[a[cs][col]];
        forn(i,col,m) {
            a[cs][i] = (a[cs][i] * la)%5;
        }
        forn(i, cs+1, n) {
            if(a[i][col] != 0) {
                int dec = a[i][col];
                forn(j,col,m) {
                    a[i][j] = (a[i][j] + 25 - a[cs][j]*dec) % 5;
                }
            }
        }
        mean.pb(col);
        cs++;
    }
    int garbage = n - cs;
    int q;
    scanf("%d", &q);
    ll ans = 1;
    forn(i,0,garbage) ans = (ans*5)%mod;
    forn(i,0,q) {
        scanf("%s", c);
        vi b;
        forn(j,0,m) b.pb(c[j] - 'a');
        forn(j,0,cs) {
            if(b[mean[j]] != 0) {
                int la = b[mean[j]];
                forn(k,0,m) b[k] = (b[k]+25-la*a[j][k]) % 5;
            }
        }
        bool can = true;
        forn(j,0,m) if(b[j] != 0) can = false;
        if(can) cout<<ans<<endl;
        else cout<<0<<endl;
    }
    
    
}