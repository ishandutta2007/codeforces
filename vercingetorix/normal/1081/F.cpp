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
int n;
int t;
int ask(int l, int r) {
    printf("? %d %d\n", l+1, r+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int find1(int l) {
    int nl = l+1;
    int nr = n-l;
    int sl = 0;
    int sr = 0;
    int al = -1;
    int ar = -1;
    while(al == -1 || ar == -1 || sl == 1 || sr == 1) {
        int lt = t;
        t = ask(l,l);
        if(abs(t-lt)%2 == nl%2) {
            int diff = t - lt;
            int f = (diff+nl)/2;
            sl ^= 1;
            if(sl == 1) f = nl-f;
            if(sr == 0) al = f;
        }
        else {
            int diff = t - lt;
            int f = (diff+nr)/2;
            sr ^= 1;
            if(sr == 1) f = nr-f;
            if(sl == 0) ar = f;
        }
    }
    return al + ar - t;;
}

int find2(int l) {
    int nl = l+2;
    int nr = n-l;
    int sl = 0;
    int sr = 0;
    int al = -1;
    int ar = -1;
    while(al == -1 || ar == -1 || sl == 1 || sr == 1) {
        int lt = t;
        t = ask(l,l+1);
        if(abs(t-lt)%2 == nl%2) {
            int diff = t - lt;
            int f = (diff+nl)/2;
            sl ^= 1;
            if(sl == 1) f = nl-f;
            if(sr == 0) al = f;
        }
        else {
            int diff = t - lt;
            int f = (diff+nr)/2;
            sr ^= 1;
            if(sr == 1) f = nr-f;
            if(sl == 0) ar = f;
        }
    }
    return al + ar - t;;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    scanf("%d %d", &n,&t);
    vi ans(n);
    if(n%2 == 0) {
        forn(i,0,n) ans[i] = find1(i);
    }
    else {
        vi s2(n-1);
        forn(i,0,n-1) s2[i] = find2(i);
        for(int i = 0; i<n; i+=2) {
            ans[i] = t;
            for(int j = 0; j<i; j+=2) ans[i]-=s2[j];
            for(int j = i+1; j<n; j+=2) ans[i]-=s2[j];
        }
        for(int i = 1; i<n; i+=2) {
            ans[i] = -t;
            for(int j = 0; j<i; j+=2) ans[i]+=s2[j];
            for(int j = i; j<n; j+=2) ans[i]+=s2[j];
        }
    }
    printf("! ");
    forn(i,0,n) printf("%d", ans[i]);
    
    
}