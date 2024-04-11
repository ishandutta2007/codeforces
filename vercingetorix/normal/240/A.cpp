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

int main()
{
//#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
//#endif
    int m,k;
    cin>>m>>k;
    readv(act,k);
    int n;
    cin>>n;
    vvi a(n);
    string s;
    vi fav(m+1,0);
    for(auto x : act) fav[x] = 1;
    int force = 0;;
    int mx = 0;
    vi ml(n), mr(n);
    forn(i,0,n) {
        cin>>s;
        int d;
        cin>>d;
        a[i].resize(d);
        int l = 0, r = 0;
        forn(j,0,d) {
            cin>>a[i][j];
            if(fav[a[i][j]]) {
                l++;
                r++;
            }
            else if(a[i][j] == 0) r++;
        }
        l = max(l, k+d-m);
        r = min(r, k);
        force = max(force, l);
        mx = max(mx, r);
        ml[i] = l;
        mr[i] = r;
    }
    forn(i,0,n) {
        int mxout = 0;
        int forceout = 0;
        forn(j,0,n) if(i!=j) {
            mxout = max(mxout, mr[j]);
            forceout = max(forceout, ml[j]);
        }
        if(mr[i] < forceout) cout<<1<<'\n';
        else if(ml[i] >= mxout) cout<<'0'<<'\n';
        else cout<<"2\n";
    }
    
    
    
}