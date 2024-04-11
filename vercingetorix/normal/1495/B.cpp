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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    readv(p,n);
//    vi l(n, 0), r(n,0);
//    int cur = 1;
//    forn(i,1,n) {
//        if(p[i] > p[i-1]) cur++;
//        else cur = 1;
//        l[i] = cur;
//    }
//    cur = 1;
//    for(int i = n-2; i>=0; i--) {
//        if(p[i] > p[i+1]) cur++;
//        else cur = 1;
//        r[i] = cur;
//    }
//    int ans = 0;
//    forn(i,1,n-1) {
//        if(l[i] > 1 && r[i] > 1 && l[i] == r[i])
//    }
    int dir = -1;
    int cnt = 2;
    int best = 2;
    vi top(1,1);
    if(p[1] > p[0]) dir = 1;
    forn(i,2,n) {
        if(dir == 1) {
            if(p[i] > p[i-1]) {
                cnt++;
            }
            else {
                dir = -1;
                cnt = 2;
            }
        }
        else {
            if(p[i] < p[i-1]) {
                cnt++;
            }
            else {
                dir = 1;
                cnt = 2;
            }
        }
        if(cnt > best) {
            best = cnt;
            top.clear();
        }
        if(cnt >= best) {
            if(dir == 1) top.pb(i);
            else top.pb(i-cnt+1);
        }
    }
    if(top.size() == 2 && top[0] == top[1] && best % 2 ==1) cout<<1;
    else cout<<0;
    
}