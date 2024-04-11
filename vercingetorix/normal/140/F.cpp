#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <unordered_set>
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
int n,k;
vi get(vi a) {
    srt(a);
    vi cand,cand2;
    forn(i,0,k+1) forn(j,n-k-1,n) if(i<=j) cand2.pb((a[i]+a[j]));
    srt(cand2);
    forn(i,0,cand2.size()) if(i==0 || cand2[i] != cand2[i-1]) cand.pb(cand2[i]);
    vi ret;
    for(auto x : cand) {
        int l = 0;
        int r = n-1;
        int need = 0;
        while(r>=l) {
            if(a[l] + a[r] == x) {
                l++;
                r--;
            }
            else if(a[l] + a[r] < x) {
                l++;
                need++;
            }
            else {
                r--;
                need++;
            }
            if(need>k) break;
        }
        if(need <= k) ret.pb(x/2);
    }
    return ret;
}
vi x,y;
vi ind;

unordered_set<ll> f;
const ll mn = 2e9+100;
ll enc(const pi & x) {
    return x.first*mn+x.second;
}

bool check(int x0, int y0) {
    int need = 0;
    forn(j,0,n) {
        pi cur = mp(2*x0- x[ind[j]], 2*y0-y[ind[j]]);
        if(!f.count(enc(cur))) need++;
        if(need>k) return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &k);
    forn(i,0,n) ind.pb(i);
    shuffle(all(ind), gen);
//    vi x(n), y(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]*=2;
        y[i]*=2;
        f.insert(enc(mp(x[i], y[i])));
    }
    if(k>=n) {
        cout<<-1;
        exit(0);
    }
    auto canx = get(x);
    auto cany = get(y);
//    for(auto c : canx) cout<<c<<' '; cout<<'\n';
//    for(auto c : cany) cout<<c<<' '; cout<<'\n';
    vpi ans;
    for(auto a : canx) for(auto b : cany) if(check(a, b)) ans.pb(mp(a,b));
    printf("%d\n", ans.size());
    for(auto pa : ans) {
        printf("%.2lf %.2lf\n", (double)pa.first/2, (double)pa.second/2);
    }
    
}