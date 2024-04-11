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

int ask(int t, int i, int j, int x) {
    printf("? %d %d %d %d\n", t, i+1, j+1, x);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}
int ind;
int val;
int n;
void find_one() {
    ind = 0;
    int t1 = ask(1, 1, 0, 1);
    if(t1 == 1) {
        val = 1;
        return;
    }
    int l = 1;
    int r = n;
    while(r-l>1) {
        int m = (r+l)/2;
        if(ask(1, 1, 0, m) <= m) r = m;
        else l = m;
    }
    val = r;
}
vi ans;

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
        ans = vi(n, -1);
        find_one();
        ans[ind] = val;
        forn(i,1,n) {
            if(val <= n/2) {
                auto ret = ask(1,ind,i,n-1);
                if(ret > val) ans[i] = ret;
                else {
                    ret = ask(2,i,ind,1);
                    ans[i] = ret;
                    val = ret;
                    ind = i;
                }
            }
            else {
                auto ret = ask(2,i,ind,1);
                if(ret < val) ans[i] = ret;
                else {
                    ret = ask(1,ind,i,n-1);
                    ans[i] = ret;
                    val = ret;
                    ind = i;
                }
            }
        }
        printf("!");
        forn(i,0,n) printf(" %d", ans[i]);
        printf("\n");
        fflush(stdout);
    }
    
    
}