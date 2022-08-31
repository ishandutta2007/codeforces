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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        read(n);
        readv(a,n);
        vi cnt(n,0);
        forn(i,0,n) cnt[a[i]]++;
        if(cnt[1] != 2) {
            printf("0\n");
            continue;
        }
        int pt = 1;
        while(cnt[pt] == 2) pt++;
        int ptr = pt;
        while(cnt[ptr] == 1) ptr++;
        int can = 1;
        forn(i,ptr,n) if(cnt[i] != 0) can  = 0;
        if(can == 0) {
            printf("0\n");
            continue;
        }
        set<int> ans;
        can = 1;
        forn(i,0,pt-1) {
            cnt[a[i]] --;
            if(cnt[a[i]] == 0) can = 0;
        }
        if(can) ans.insert(pt-1);
        forn(i,0,pt-1) cnt[a[i]] ++;
        can = 1;
        forn(i,n-pt+1,n) {
            cnt[a[i]] --;
            if(cnt[a[i]] == 0) can = 0;
        }
        if(can) ans.insert(n-pt+1);
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x, n-x);
    }
    
    
}