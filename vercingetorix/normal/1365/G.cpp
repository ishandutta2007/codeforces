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

typedef unsigned long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<unsigned long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n;
vll ROK;

ll req(vi a) {
    vi b;
    sort(all(a));
    int prev = -1;
    for(auto x : a) {
        if (x == 511 || x == 767 || x == 895 || x == 959 || x == 991) continue;
        if (x == 1020) x = 991;
        if (x == 1018) x = 959;
        if (x == 1017) x = 895;
        if (x == 1016) x = 767;
        if (x == 1014) x = 511;
        if (x==prev) continue;
        if (x > 0 && x <= n) b.pb(x);
        prev = x;
    }
    if (b.size() == 0) return 0;
    cout << "? " << b.size();
    for(auto x : b) cout << ' '<< x;
    cout << endl;
    cout.flush();
    ll x;
    cin>>x;
//    ll x = 0;
//    for(auto i : b) x |= ROK[i];
    return x;
}

void go(vll ans) {
    forn(i,0,10) cout<<ans[i]<<' '; cout<<endl;
    forn(i,0,10) cout<<ROK[i]<<' '; cout<<endl;
    forn(i,1,n+1) {
        ll cur = 0;
        forn(j,1,n+1) if (j != i) cur |= ROK[j];
        if(ans[i] != cur) {
            cout<<"WEOND" << ' ' << i <<endl;
        }
    }
    cout<<"GOOD?\n";
    exit(0);
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    vll d2(1, 1);
    forn (i,0,63) d2.pb(d2.back()*2);
    cin >> n;
    vi cnt(63, 0);
    vi prince(63,0);
    forn (i,0,10) {
        vi cur;
        forn (j,0,1024) if ((j&d2[i]) > 0) cur.pb(j);
        ll x = req(cur);
        forn (j,0,63) {
            if (x&d2[j]) {
                prince[j] += d2[i];
                cnt[j] ++;
            }
        }
    }
    vi v1256, v1357, v1234;
    forn(i,0,63) {
        if(cnt[i] == 2) v1256.pb(prince[i]), v1234.pb(prince[i]);
        else if(cnt[i] == 3) v1357.pb(prince[i]), v1234.pb(prince[i]);
        else if(cnt[i] == 4) v1234.pb(prince[i]);
        else if(cnt[i] == 5) v1256.pb(prince[i]), v1357.pb(prince[i]);
        else if(cnt[i] == 6) v1256.pb(prince[i]);
        else if(cnt[i] == 7) v1357.pb(prince[i]);
    }
    vi take(1024,1);
    forn(i,0,63) if(cnt[i] >= 2 && cnt[i] <= 8) take[prince[i]] = 0;
    forn(i,0,1024) {
        if (take[i]) v1256.pb(i), v1357.pb(i), v1234.pb(i);
    }
    ll x1256 = req(v1256);
    ll x1357 = req(v1357);
    ll x1234 = req(v1234);
    ll def = 0;
    vi solo(63, 0);
    forn(i,0,63) {
        if(cnt[i] > 0) def += d2[i];
        ll tp = 0;
        int p = cnt[i];
        if(p >= 5) tp |= x1234;
        if(p==3 || p==4 || p==7 || p == 8) tp |= x1256;
        if(p%2 == 0) tp |= x1357;
        if(p == 1) solo[i] = 1;
        else if(p < 9 && (tp&d2[i]) == 0) solo[i] = 1;
    }
    vll ans(1024, def);
    forn(i,0,63) if(cnt[i] > 0 && solo[i] == 1) ans[prince[i]] -= d2[i];
    ans[511] = ans[1014];
    ans[767] = ans[1016];
    ans[895] = ans[1017];
    ans[959] = ans[1018];
    ans[991] = ans[1020];
//    go(ans);
    cout<<"!";
    forn(i,1,n+1) cout<<' '<<ans[i]; cout<<endl;
}