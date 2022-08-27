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
vs a;
vpi plates;
void go(int i, int j) {
    for(auto x : plates) if(abs(x.first-i) <= 1 && abs(x.second - j) <= 1) return;
    plates.pb(mp(i,j));
    a[i][j] = '1';
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int h,w;
        cin>>h>>w;
        plates.clear();
        a = vs(h, string(w, '0'));
        plates.pb(mp(0,0));
        a[0][0] = '1';
        forn(i,1,w) {
            go(0,i);
        }
        forn(i,1,h) go(i,w-1);
        for(int i = w-2; i>=0; i--) go(h-1, i);
        for(int i = h-2; i>=1; i--) go(i, 0);
        forn(i,0,h) printf("%s\n", a[i].c_str());
    }
    
    
}