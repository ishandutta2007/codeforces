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
vvi a(3, vi(3));

int rook() {
    int x = 0;
    int y = 0;
    forn(i,0,3) forn(j,0,3) if(a[i][j] == 0){
        x=  i;
        y = j;
    }
    vi vis(9,0);
    vis[0] = 1;
    int ret = 0;
    forn(it,0,8) {
        int nx = 10;
        int x2,y2;
        forn(i,0,3) forn(j,0,3) {
            if(i==x || j==y) if(vis[a[i][j]] == 0) if(a[i][j] < nx) {
                nx = a[i][j];
                x2 = i;
                y2 = j;
            }
        }
        if(nx == 10) {
            ret ++;
            forn(i,0,3) forn(j,0,3) {
                if(vis[a[i][j]] == 0) if(a[i][j] < nx) {
                    nx = a[i][j];
                    x2 = i;
                    y2 = j;
                }
            }
        }
        vis[nx] = 1;
        x = x2;
        y = y2;
    }
    return ret;
}

int queen() {
    int x = 0;
    int y = 0;
    forn(i,0,3) forn(j,0,3) if(a[i][j] == 0){
        x=  i;
        y = j;
    }
    vi vis(9,0);
    vis[0] = 1;
    int ret = 0;
    forn(it,0,8) {
        int nx = 10;
        int x2,y2;
        forn(i,0,3) forn(j,0,3) {
            if(i==x || j==y || i-j == x-y || i+j == x+y) if(vis[a[i][j]] == 0) if(a[i][j] < nx) {
                nx = a[i][j];
                x2 = i;
                y2 = j;
            }
        }
        if(nx == 10) {
            ret ++;
            forn(i,0,3) forn(j,0,3) {
                if(vis[a[i][j]] == 0) if(a[i][j] < nx) {
                    nx = a[i][j];
                    x2 = i;
                    y2 = j;
                }
            }
        }
        vis[nx] = 1;
        x = x2;
        y = y2;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
//    vi ord;
//    forn(i,0,9) ord.pb(i);
//    do {
//        forn(i,0,3) forn(j,0,3) a[i][j] = ord[i*3+j];
//        vi vis(9,0);
//        if(rook() < queen()) {
//            forn(i,0,3) {
//                forn(j,0,3) cout<<a[i][j]; cout<<'\n';
//            }
//            cout<<'\n';
//        }
//    } while(next_permutation(all(ord)));
    int n;
    cin>>n;
    if(n<=2) cout<<-1;
    else {
        vvi a(n, vi(n,0));
        int cur = n*n;
        a[2][0] = cur--;
        a[1][2] = cur--;
        a[2][2] = cur--;
        a[2][1] = cur--;
        a[1][0] = cur--;
        a[0][2] = cur--;
        a[1][1] = cur--;
        a[0][1] = cur--;
        a[0][0] = cur--;
        forn(k,3,n) {
            if(k%2) {
                forn(i,0,k+1) a[k][i] = cur--;
                for(int i = k-1; i>=0; i--) a[i][k] = cur--;
            }
            else {
                forn(i,0,k+1) a[i][k] = cur--;
                for(int i = k-1; i>=0; i--) a[k][i] = cur--;
            }
        }
        forn(i,0,n) {
            forn(j,0,n) cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
    
}