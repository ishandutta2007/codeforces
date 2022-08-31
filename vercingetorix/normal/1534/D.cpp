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
vpi e;

vi ask(int v) {
    printf("? %d\n", v+1);
    fflush(stdout);
    readv(a, n);
    forn(i,0,n) if(a[i] == 1) {
        if(i<v) e.pb(mp(i+1,v+1));
        else e.pb(mp(v+1,i+1));
    }
    return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    
    vi d0 = ask(0);
    vi cnt(2,0);
    forn(i,1,n) cnt[d0[i]%2]++;
    int r = 0;
    if(cnt[1] < cnt[0]) r = 1;
    forn(i,1,n) if(d0[i]%2==r) ask(i);
    srt(e);
    printf("!\n");
    forn(i,0,e.size()) {
        if(i==0 || e[i]!=e[i-1]) printf("%d %d\n", e[i].first, e[i].second);
    }
    
    
}