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
vs a(3);
int n;
bool did = false;
void go(int p, int q, char x) {
    if (did) return;
    vi v1, v2;
    forn(i,0,2*n) {
        if(a[p][i] == x) v1.pb(i);
        if(a[q][i] == x) v2.pb(i);
    }
    if(v1.size() < n or v2.size() < n) return;
    did = true;
    v1.resize(n);
    v2.resize(n);
    int i1 = 0;
    int i2 = 0;
    string ans;
    v1.pb(2*n);
    v2.pb(2*n);
    forn(i,0,n+1) {
        while(i1<v1[i]) ans.pb(a[p][i1++]);
        while(i2<v2[i]) ans.pb(a[q][i2++]);
        ans.pb(x);
        i1++;
        i2++;
    }
    ans.pop_back();
    printf("%s\n", ans.c_str());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[200500];
    while(t--) {
        scanf("%d\n", &n);
        forn(i,0,3) {
            scanf("%s", c);
            a[i] = string(c);
        }
        did = false;
        forn(i,0,3) forn(j,i+1,3) forn(sym,0,2) go(i,j,'0'+sym);
    }
    
}