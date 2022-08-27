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
    int n,v;
    scanf("%d %d", &n, &v);
    vvpi a(3);
    forn(i,0,n) {
        int t,p;
        scanf("%d %d", &t, &p);
        a[t].pb(mp(p,i));
    }
    vi ans;
    int sum = 0;
    srt(a[1]);
    if(v%2 == 1) {
        if(!a[1].empty()) {
            sum += a[1].back().first;
            ans.pb(a[1].back().second);
            a[1].pop_back();
        }
        v--;
    }
    reverse(all(a[1]));
    srtrev(a[2]);
    int pt1 = 0;
    int pt2 = 0;
    while(v > 0) {
        if(pt1 == a[1].size() && pt2 == a[2].size()) break;
        if(pt2 == a[2].size()) {
            sum += a[1][pt1].first;
            v--;
            ans.pb(a[1][pt1].second);
            pt1++;
        }
        else if(pt1 == a[1].size()) {
            sum += a[2][pt2].first;
            v-=2;
            ans.pb(a[2][pt2].second);
            pt2++;
        }
        else {
            int cand1 = a[1][pt1].first;
            if(pt1+1 < a[1].size()) cand1 += a[1][pt1+1].first;
            if(cand1 >= a[2][pt2].first) {
                sum += cand1;
                ans.pb(a[1][pt1].second);
                pt1++;
                if(pt1 < a[1].size()) {
                    ans.pb(a[1][pt1].second);
                    pt1++;
                }
                v-=2;
            }
            else {
                sum += a[2][pt2].first;
                ans.pb(a[2][pt2++].second);
                v-=2;
            }
        }
    }
    printf("%d\n", sum);
    for(auto x : ans) printf("%d ", x+1);
    
    
    
}