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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin>>n;
    vi a,b;
    forn(i,0,n) {
        int x,y,z;
        cin>>x>>y>>z;
        a.pb(x*4+y*2+z);
    }
    forn(i,0,n) {
        int x,y,z;
        cin>>x>>y>>z;
        b.pb(x*4+y*2+z);
    }
    vpi e;
    vi ts(n,0);
    vvi fr(8);
    fr[7].pb(0);
    vi done(n,0);
    done[0] = 1;
    forn(i,0,n) if(a[i] == 0) done[i] = 1;
    fr[0].pb(-1);
    forn(it,0,9) {
        forn(i,0,n) if(done[i] == 0) {
            if(!fr[a[i]].empty()) {
                for(auto x : fr[a[i]]) e.pb(mp(x,i));
                done[i]  =1;
                if(fr[a[i]&b[i]].empty()) {
                    ts[i] = 1;
                    fr[a[i]&b[i]].pb(i);
                }
                else if(fr[a[i]].size() > 1) {
                    fr[a[i]] = vi(1,i);
                }
            }
        }
        forn(i,0,8) forn(j,0,8) if(!fr[i].empty() && !fr[j].empty() && fr[i|j].empty()) {
            for(auto x : fr[i]) fr[i|j].pb(x);
            for(auto x : fr[j]) fr[i|j].pb(x);
        }
    }
    forn(i,0,n) if(done[i] == 0) {
        cout<<"Impossible\n";
        exit(0);
    }
    cout<<"Possible\n";
    forn(i,0,n) cout<<ts[i]<<' ';
    cout<<'\n';
    cout<<e.size()<<'\n';
    for(auto x : e) cout<<x.first+1<<' '<<x.second+1<<'\n';
    
    
}