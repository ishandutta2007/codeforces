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
const int A = 70;
int d[A][A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d", &n, &m);
        forn(i,0,n+1) forn(j,i+1,n+1) d[i][j] = 0;
        vi col(m);
        forn(i,1,m+1) {
            int u,v;
            scanf("%d %d %d", &u, &v, &col[i-1]);
            if(u > v) swap(u,v);
            d[u][v] = i;
        }
        vvi as;
        vi b;
        forn(i,0,m) if(col[i] != -1) {
            as.pb(vi(1, i));
            b.pb(col[i] - 1);
        }
        forn(i,1,n+1) forn(j,i+1,n+1) forn(k,j+1,n+1) {
            if(d[i][j] && d[i][k] && d[j][k]) {
                vi x;
                x.pb(d[i][j] - 1);
                x.pb(d[i][k] - 1);
                x.pb(d[j][k] - 1);
                as.pb(x);
                b.pb(0);
            }
        }
        vi imploc(m, - 1);
        vvi a;
        vi c;
        int bad = 0;
        forn(i,0,as.size()) {
            vi cur(m, 0);
            int r = b[i];
            for(auto x : as[i]) cur[x] = 1;
            for(auto x : as[i]) {
                if(imploc[x] != -1) {
                    int j = imploc[x];
                    forn(k,0,m) {
                        cur[k] = cur[k] + 3 - a[j][k];
                        if(cur[k] >= 3) cur[k]-=3;
                    }
                    r = (3 + r - c[j])%3;
                }
            }
            int nim = -1;
            forn(i,0,m) if(cur[i] != 0) nim = i;
            if(nim == -1 && r != 0) {
                bad = 1;
                break;
            }
            if(nim == -1) continue;
            if(cur[nim] == 2) {
                forn(i,0,m) if(cur[i] != 0) cur[i]^=3;
                if(r != 0) r^=3;
            }
            forn(j,0,a.size()) {
                if(a[j][nim] == 1) {
                    forn(k,0,m) {
                        a[j][k] = a[j][k] + 3 - cur[k];
                        if(a[j][k] >= 3) a[j][k]-=3;
                    }
                    c[j] = (3+c[j] -r)%3;
                }
                else if(a[j][nim] == 2){
                    forn(k,0,m) {
                        a[j][k] = a[j][k] + cur[k];
                        if(a[j][k] >= 3) a[j][k]-=3;
                    }
                    c[j] = (c[j] +r)%3;
                }
            }
            imploc[nim] = a.size();
            a.pb(cur);
            c.pb(r);
        }

        if(bad) printf("-1\n");
        else {
            forn(i,0,m) if(imploc[i] == -1) col[i] = 0;
            forn(i,0,m) if(imploc[i] != -1) {
                int j = imploc[i];
                int r = c[j];
                forn(k,0,m) if(k!=i) r -= a[j][k] * col[k];
                col[i] = (3+r%3)%3;
            }
            forn(i,0,m) printf("%d ", col[i] + 1);
            printf("\n");
//            printf("1\n");
        }
//        cout<<a.size()<<endl;
    }
    
    
}