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

int p, q;
vi cdec;

pi add(int x) {
    printf("+ %d\n", x);
    cdec[x] ++;
    fflush(stdout);
    int a,b;
    scanf("%d %d", &a, &b);
    pi ret = mp(a-p, b-q);
    p = a;
    q = b;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi t3to(20000, -1);
    forn(i,1,200) {
        t3to[i*(i-1)/2] = i;
    }
    int n;
    scanf("%d", &n);
    int wn = n;
    scanf("%d %d", &p, &q);
    vi ans(n+4, 0);
    cdec = vi(n+4, 0);
    while(n >= 4) {
        pi res = add(n-2);
        pi res2 = add(n);
        pi res3 = add(n-1);
        pi res4 = add(n);
        res2.second -= ans[n+1]*ans[n+2];
        if(res2.second == 0) {
            ans[n-1] = 1;
        }
        else ans[n-1] = t3to[res3.first] + 1;
        ans[n] = t3to[res4.first]+1;
        res4.second -= ans[n+1]*ans[n+2] + ans[n+1]*ans[n-1];
        ans[n-2] = res4.second / ans[n-1];
        res3.second -= ans[n+1]*(ans[n] - 1) + (ans[n] - 1)*ans[n-2];
        ans[n-3] = res3.second / ans[n-2];
        n-=4;
    }
    if(n==1) {
        pi res = add(2);
        ans[2]++;
        ans[1] = (res.second - ans[3]*ans[4])/ans[3];
    }
    if(n==2) {
        pi res = add(3);
        ans[3]++;
        pi res2 = add(2);
        res2.second -= ans[3]*ans[4];
        ans[1] = res2.second / ans[3];
        res.second -= ans[4]*ans[5];
        if(res.second == 0) ans[2] = 1;
        else ans[2] = t3to[res2.first] + 1;
    }
    if(n==3) {
        pi res = add(4);
        pi res2 = add(3);
        pi res3 = add(2);
        ans[4]++;
        res.second -= ans[5]*ans[6];
        if(res.second == 0) ans[3] = 1;
        else ans[3] = t3to[res2.first]+1;
        res2.second -= ans[4]*ans[5];
        if(res2.second == 0) ans[2] = 1;
        else ans[2] = t3to[res3.first]+1;
        ans[1] = (res3.second - ans[3]*ans[4])/ans[3];
    }
    

    printf("!");
    forn(i,1,wn+1) printf(" %d", ans[i] - cdec[i]);
    printf("\n");
}