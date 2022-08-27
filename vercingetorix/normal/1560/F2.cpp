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

int test(int n) {
    vi cnt(10, 0);
    int ret =0;
    while(n>0) {
        int k = n%10;
        n/=10;
        if(cnt[k] == 0) ret++;
        cnt[k]++;
    }
    return ret;
}

int mind(int n) {
    vi cnt(10, 0);
    while(n>0) {
        cnt[n%10]=1;
        n/=10;
    }
    forn(i,0,10) if(cnt[i] == 1) return i;
    return -1;
}

int get(int n, int k) {
    while(1) {
        if(test(n) <= k) return n;
        if(n%10 == 0) {
            int res = get(n/10, k);
            return 10*res + mind(res);
        }
        n++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        printf("%d\n", get(n,k));
//        string s = to_string(n);
//        vi has(10,0);
//        int cdif = 0;
//        int pt = 0;
//        int last = -1;
//        while(pt < s.size() && (has[s[pt]-'0'] > 0 || cdif < k)) {
//            if(has[s[pt]-'0'] == 0) {
//                cdif++;
//                last = pt;
//            }
//            has[s[pt]-'0'] += 1;
//            pt++;
//        }
//        if(pt == s.size()) {
//            printf("%s\n", s.c_str());
//            continue;
//        }
//        int v = s[pt] -'0';
//        int ptm = 0;
//        while(has[ptm] == 0) ptm++;
//        int done = 0;
//        forn(i,v+1,10) {
//            if(has[i]) {
//                s[pt] = i;
//                forn(j,pt+1,s.size()) s[j] = ptm;
//                done = 1;
//                break;
//            }
//        }
//        if(!done) {
//
//        }
//
    }
    
}