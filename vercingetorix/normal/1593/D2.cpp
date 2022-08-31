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
int n;
vi a;
int cnt[2000100];
int touch[100];
int softmod(int x, int d) {
    if(d==0) return x+1000000;
    int ret = x%d;
    if(ret<0) return ret+d;
    else return ret;
}

bool can(int d) {
    bool ret = false;
    forn(i,0,n) {
        int cur = softmod(a[i], d);
        cnt[cur]++;
        if(cnt[cur] >= n/2) {
            ret = true;
            break;
        }
        touch[i] = cur;
    }
    forn(i,0,n) cnt[touch[i]] = 0;
    return ret;
}
int ans;

void proc(int cand) {
    if(ans>=cand) return;
    if(can(cand)) ans = cand;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        scanf("%d", &n);
        readv(ava,n);
        a = ava;
        srt(a);
        if(can(0)) {
            printf("-1\n");
            continue;
        }
        ans = 1;
        forn(i,0,n) forn(j,i+1,n) {
            if(a[i]!=a[j]) {
                int m = a[j]-a[i];
                for(int f = 1; f*f<=m; f++) {
                    if(m%f == 0) {
                        proc(f);
                        proc(m/f);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    
    
}