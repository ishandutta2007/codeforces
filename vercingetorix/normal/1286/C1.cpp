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
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
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
char c[1000];
vs req(int l, int r) {
    printf("? %d %d\n", l + 1, r+1);
    fflush(stdout);
//    if(r==2) exit(0);
    int k = r-l+1;
    vs ret;
    forn(i,0,k*(k+1)/2) {
        scanf("%s", c);
        ret.pb(string(c));
    }
    return ret;
}
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    vs a = req(0,n-1);
    vector<vs> byl(101);
    for(auto x : a) byl[x.size()].pb(x);
    forn(i,0,100) for(auto & x :byl[i]) sort(all(x));
    vvi simp;
    forn(l,0,n/2) {
        int r = n-1-l;
        int len = r+1;
        vi cnt(26,0);
        for(auto s : byl[r]) for(auto x : s) cnt[x-'a']++;
        forn(i,0,l) for(auto x : simp[i]) cnt[x] += l+1-i;
        for(auto x : byl[n][0]) cnt[x-'a'] -= (l+2);
        simp.pb(vi());
        forn(i,0,26) while(cnt[i] < 0) {
            cnt[i] ++;
            simp.back().pb(i);
        }
    }
//    string ans(n, '*');
    vi ans(n);
    int pt = 0;
    while(pt<simp.size() && simp[pt][0] == simp[pt][1]) {
        ans[pt] = char('a'+simp[pt][0]);
        ans[n-1-pt] = ans[pt];
        pt++;
    }
    if(n%2 == 1) {
        vi cnt(26,0);
        for(auto x : byl[n][0]) cnt[x-'a'] += 1;
        for(auto x : simp) for(auto y : x) cnt[y]--;
        forn(i,0,26) if(cnt[i]) simp.pb( vi(2, i));
    }
    if(n==1) {
        cout<<"! "<<char('a'+simp[0][0])<<endl;
        return 0;
    }
    vvi simpn = simp;
    n--;
    
    a = req(0,n-1);
    byl = vector<vs> (101);
    for(auto x : a) byl[x.size()].pb(x);
    forn(i,0,100) for(auto & x :byl[i]) sort(all(x));
    simp.clear();
    forn(l,0,n/2) {
        int r = n-1-l;
        int len = r+1;
        vi cnt(26,0);
        for(auto s : byl[r]) for(auto x : s) cnt[x-'a']++;
        forn(i,0,l) for(auto x : simp[i]) cnt[x] += l+1-i;
        for(auto x : byl[n][0]) cnt[x-'a'] -= (l+2);
        simp.pb(vi());
        forn(i,0,26) while(cnt[i] < 0) {
            cnt[i] ++;
            simp.back().pb(i);
        }
    }
    pt = 0;
    while(pt<simp.size() && simp[pt][0] == simp[pt][1]) {
        ans[pt] = char('a'+simp[pt][0]);
        ans[n-1-pt] = ans[pt];
        pt++;
    }
    if(n%2 == 1) {
        vi cnt(26,0);
        for(auto x : byl[n][0]) cnt[x-'a'] += 1;
        for(auto x : simp) for(auto y : x) cnt[y]--;
        forn(i,0,26) if(cnt[i]) simp.pb( vi(2, i));
    }
    
    n++;
    a = req(0,0);
    ans[0] = int(a[0][0]-'a');
    ans[n-1] = simpn[0][0];
    if(simpn[0][0] == ans[0]) ans[n-1] = simpn[0][1];
    pt = 0;
    while(2*pt <= n-2) {
        ans[n-2-pt] = simp[pt][0];
        if(simp[pt][0] == ans[pt]) ans[n-2-pt] = simp[pt][1];
        if(n-2-pt <= pt+1) break;
        ans[pt+1] = simpn[pt+1][0];
        if(simpn[pt+1][0] == ans[n-2-pt]) ans[pt+1] = simpn[pt+1][1];
        pt++;
    }
    cout<<"! ";
    forn(i,0,n) cout<<char('a'+ans[i]);
    
    
}