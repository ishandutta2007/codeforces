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
int n;
vs a;
//vpi dir = {{1,0}, {-1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vpi dir = {{1,0}, {1,1}, {0,1}};

int check(string s) {
    forn(i,0,n) forn(j,0,n) {
        for(auto x : dir) {
//            int i2 = i + x.first * (s.size() - 1);
//            int j2 = j + x.second * (s.size() - 1);
//            if(i2 < 0 || j2 < 0 || i2 >=n || j2>=n) continue;
            int cx = i;
            int cy = j;
            string t;
            forn(i,0,s.size()) {
                t.pb(a[cx][cy]);
                cx += x.first;
                cy += x.second;
                if(cx == -1) cx = n-1;
                if(cy == -1) cy = n-1;
                if(cx == n) cx = 0;
                if(cy == n) cy = 0;
            }
            if(s == t) return 1;
        }
    }
    return 0;
}

int check2(string s) {
    vvi d(n, vi(n, 0));
    forn(i,0,n) forn(j,0,n) if(a[i][j] == s[0]) d[i][j] = 1;
    int bad = 0;
    forn(it,1,s.size()) {
        forn(i,0,n) forn(j,0,n) {
            if(d[i][j] == it) {
                for(auto x : dir) {
                    int i1 = i + x.first;
                    int j1 = j+x.second;
                    if(i1>=0 && j1>=0 &&i1<n && j1<n &&a[i1][j1] == s[it]) d[i1][j1] = it+1;
                }
            }
        }
    }
    forn(i,0,n) forn(j,0,n) if(d[i][j] == s.size()) bad = 1;
    return bad;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //    cout<<"YES\n";
    //    exit(0);
    
    cin>>n;
    a.resize(n);
    forn(i,0,n) cin>>a[i];
    int theseus = check("theseus");
    if(theseus) printf("YES\n");
    else printf("NO\n");
    int minotaur = check2("minotaur");
    int ariadne = check("ariadne");
//    if(minotaur == 0 && (theseus | ariadne)) printf("YES\n");
//    if(ariadne) printf("YES\n");
//    else if(minotaur == 0) printf("YES\n");
//    else if(theseus) printf("YES\n");
//    else printf("NO\n");
    //    if(safe && bad == 0) printf("YES\n");
    //    else printf("NO\n");
    
    //    forn(i,0,n) forn(j,i+1,n) swap(a[i][j], a[j][i]);
    //    forn(i,0,n) cout<<a[i]<<'\n';
    //    string s = "minotaur";
    //    vvi d(n, vi(n, 0));
    //    forn(i,0,n) forn(j,0,n) if(a[i][j] == 'm') d[i][j] = 1;
    
    //    int bad = 0;
    //    forn(it,1,8) {
    //        forn(i,0,n) forn(j,0,n) {
    //            if(d[i][j] == it) {
    //                for(auto x : dir) {
    //                    int i1 = i + x.first;
    //                    int j1 = j+x.second;
    //                    if(i1>=0 && j1>=0 &&i1<n && j1<n &&a[i1][j1] == s[it]) d[i1][j1] = it+1;
    //                }
    //            }
    //        }
    //    }
    //    forn(i,0,n) forn(j,0,n) if(d[i][j] == 8) bad = 1;
    //    if(bad) printf("NO\n");
    //    else printf("YES\n");
    
    
}