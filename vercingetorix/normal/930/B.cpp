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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    cin>>s;
    int n = s.size();
    vs ss(1, s);
    forn(i,0,n-1) {
        string sss = ss.back().substr(1);
        sss.pb(ss.back()[0]);
        ss.pb(sss);
    }
    vi u;
    forn(i,0,n) u.pb(26*int(ss[i][0]-'a'));
//    int ans = 0;
    vi ans(26,0);
    forn(i,1,n) {
        vvi cnt(26, vi(26, 0));
        forn(j,0,n) {
            cnt[int(ss[j][0] - 'a')][int(ss[j][i] - 'a')] ++ ;
        }
        forn(f, 0, 26) {
            int cand = 0;
            forn(j,0,26) {
                if(cnt[f][j] == 1) cand++;
            }
            ans[f] = max(ans[f], cand);
        }
    }
    vi cf(26,0);
    forn(i,0,n) cf[int(ss[i][0] - 'a')]++;
    int uka = 0;
    forn(i,0,26) uka += ans[i];
    printf("%.10lf", double(uka)/n);
    
    exit(0);
    
}