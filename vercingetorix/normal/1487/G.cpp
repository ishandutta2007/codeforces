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

const long long mod = 998244353;
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

const int A = 405;
ll d2[2][A][A][3][3];
ll d1[2][A][2][2];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(p1,0,3) forn(p2,0,3) {
        int w1 = (p1==0) + (p2==0);
        int w2 = (p1==1) + (p2==1);
        int var = (1+23*(p1==2))*(1+23*(p2==2));
        d2[0][w1][w2][p1][p2] = var;
    }
    forn(p1,0,2) forn(p2,0,2) {
        int w1 = (p1==0) + (p2==0);
        int var = (1+24*(p1==1))*(1+24*(p2==1));
        d1[0][w1][p1][p2] = var;
    }
//    cout<<0<<'\n';
//    forn(w1,0,5) forn(p1,0,2) forn(p2,0,2) if(d1[0][w1][p1][p2]!=0) cout<<w1<<' '<<p1<<' '<<p2<<' '<<d1[0][w1][p1][p2]<<'\n';
    int n;
    read(n);
    forn(lb,2,n) {
        int l = lb%2;
        int l1 = l^1;
        forn(i,0,A)forn(j,0,A) forn(p1,0,3) forn(p2,0,3) d2[l1][i][j][p1][p2] = 0;
        forn(i,0,A) forn(p1,0,2) forn(p2,0,2) d1[l1][i][p1][p2] = 0;
        forn(w,0,lb+1) forn(p1,0,2) forn(p2,0,2) if(d1[l][w][p1][p2] != 0) {
            ll cur = d1[l][w][p1][p2];
            if(p1 == 0) d1[l1][w][p2][1] = (d1[l1][w][p2][1] + 25*cur)%mod;
            else {
                d1[l1][w][p2][1] = (d1[l1][w][p2][1] + 24*cur)%mod;
                d1[l1][w+1][p2][0] = (d1[l1][w+1][p2][0] + cur)%mod;
            }
        }
        forn(w1,0,lb+1) forn(w2,0,lb+1-w1) forn(p1,0,3) forn(p2,0,3) if(d2[l][w1][w2][p1][p2] != 0) {
            ll cur = d2[l][w1][w2][p1][p2];
            if(p1 == 2) {
                d2[l1][w1+1][w2][p2][0] = (d2[l1][w1+1][w2][p2][0] + cur)%mod;
                d2[l1][w1][w2+1][p2][1] = (d2[l1][w1][w2+1][p2][1] + cur)%mod;
                d2[l1][w1][w2][p2][2] = (d2[l1][w1][w2][p2][2] + 23*cur)%mod;
            }
            else if(p1 == 0) {
                d2[l1][w1][w2+1][p2][1] = (d2[l1][w1][w2+1][p2][1] + cur)%mod;
                d2[l1][w1][w2][p2][2] = (d2[l1][w1][w2][p2][2] + 24*cur)%mod;
            }
            else if(p1 == 1) {
                d2[l1][w1+1][w2][p2][0] = (d2[l1][w1+1][w2][p2][0] + cur)%mod;
                d2[l1][w1][w2][p2][2] = (d2[l1][w1][w2][p2][2] + 24*cur)%mod;
            }
        }
//        cout<<lb<<'\n';
//        forn(w1,0,5) forn(p1,0,2) forn(p2,0,2) if(d1[l1][w1][p1][p2]!=0) cout<<w1<<' '<<p1<<' '<<p2<<' '<<d1[l1][w1][p1][p2]<<'\n';
//        cout<<lb<<'\n';
//        forn(w1,0,5) forn(w2,0,5) forn(p1,0,3) forn(p2,0,3) if(d2[l1][w1][w2][p1][p2]!=0) cout<<w1<<' '<<w2<<' '<<p1<<' '<<p2<<' '<<d2[l1][w1][w2][p1][p2]<<'\n';
    }
//    cout<<d1[0][2][0][0];
//    exit(0);
    readv(c, 26);
    ll ans = 26*26;
    forn(i,0,n-2) ans = ans*25%mod;
    forn(i,0,26) forn(tk,c[i]+1,n+1) forn(p1,0,2) forn(p2,0,2) ans = ans - d1[n%2][tk][p1][p2];
    forn(i,0,26) forn(j,i+1,26) forn(t1,c[i]+1,n+1) forn(t2,c[j]+1,n+1) forn(p1,0,3) forn(p2,0,3) ans = ans + d2[n%2][t1][t2][p1][p2];
    ans = (ans%mod+mod)%mod;
    cout<<ans;
    
    
}