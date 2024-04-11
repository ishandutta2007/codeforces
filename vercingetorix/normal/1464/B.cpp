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
char c[100500];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%s", c);
    ll x,y;
    scanf("%lld %lld", &x, &y);
    string s(c);
    int n = s.size();
    if(x>y) {
        swap(x,y);
        forn(i,0,n) {
            if(s[i] == '0') s[i]='1';
            else if(s[i] == '1') s[i] = '0';
        }
    }
    vvi dl(n);
    vvi dr(n);
    vi cur(3,0);
    ll ans = 0;
    vll il(n), ir(n);
    
    forn(i,0,n) {
        if(s[i] == '0') cur[0]++;
        else if(s[i] == '1') cur[1]++;
        else cur[2]++;
        dl[i] = cur;
        if(s[i] == '0') ans += y*cur[1];
        else if(s[i] == '1') ans += x*cur[0];
    }
    cur = vi(3,0);
    for(int i = n-1; i>=0; i--) {
        if(s[i] == '0') cur[0]++;
        else if(s[i] == '1') cur[1]++;
        else cur[2]++;
        dr[i] = cur;
    }
    ll curinv = 0;
    forn(i,0,n) {
        if(s[i] == '?') {
            curinv += y*dl[i][1] + x*dr[i][1];
        }
        il[i] = curinv;
    }
    curinv = 0;
    for(int i = n-1; i>=0; i--) {
        if(s[i] == '?') {
            curinv += x*dl[i][0] + y*dr[i][0];
        }
        ir[i] = curinv;
    }
    ll best = 1e18;
    forn(l,-1,n) {
        int r = l+1;
        ll cand = 0;
        if(l>=0) cand += il[l];
        if(r<n) cand += ir[r];
        if(l>=0 && r<n) {
            cand += x*ll(dl[l][2]) * ll(dr[r][2]);
        }
        best = min(best, cand);
    }
    cout<<ans+best;

    
    
}