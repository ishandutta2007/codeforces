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
vpi sw;
vi ans;
vvi  a;
void yes() {
    printf("Yes\n");
    while(!sw.empty()) {
        swap(ans[sw.back().first], ans[sw.back().second]);
        sw.pop_back();
    }
    for(auto x : ans) printf("%d ", x);
    printf("\n");
    exit(0);
}
void no() {
    printf("No\n");
    exit(0);
}
int n,m;
int test(vi & x) {
    forn(i,0,n) {
        int bad = 0;
        forn(j,0,m) if(x[j] != a[i][j]) bad++;
        if(bad > 2) return i;
    }
    ans = x;
    yes();
    return -1;
}

int test2(vi & x) {
    int pt = 0;
    while(x[pt] != -1) pt++;
    vi need;
    forn(i,0,n) {
        int bad = 0;
        forn(j,0,m) if(j!=pt && x[j] != a[i][j]) bad++;
        if(bad > 2) return i;
        if(bad == 2) need.pb(a[i][pt]);
    }
    sort(all(need));
    if(!need.empty() && need.back() != need[0]) return -1;
    ans = x;
    ans[pt] = 1;
    if(!need.empty()) ans[pt] = need[0];
    yes();
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    a = vvi(n, vi(m));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    ans = vi(m, -1);
    int p = test(a[0]);
    vi bad;
    forn(j,0,m) if(a[p][j] != a[0][j]) bad.pb(j);
    if(bad.size() > 4) no();
    if(bad.size() == 4) {
        forn(i1,0,4) forn(i2,i1+1, 4) {
            vi x = a[0];
            x[bad[i1]] = a[p][bad[i1]];
            x[bad[i2]] = a[p][bad[i2]];
            test(x);
        }
        no();
    }
    forn(ind,0,3) {
        vi x = a[0];
        x[bad[ind]] = a[p][bad[ind]];
        test(x);
        x = a[p];
        x[bad[ind]] = a[0][bad[ind]];
        test(x);
    }
    forn(ind,0,3) {
        forn(i2, 0, 3) {
            if(i2==ind) continue;
            vi x = a[0];
            x[bad[ind]] = -1;
            x[bad[i2]] = a[p][bad[i2]];
            test2(x);
        }
    }
    no();
    
}