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
    string s,t;
    int n;
    scanf("%d\n", &n);
    getline(cin, s);
    getline(cin, t);
    int c01 = 0;
    int c10 = 0;
    vi lol;
    forn(i,0,n) {
        if(s[i] == '0' && t[i] == '1') {
            c01 ++;
            lol.pb(0);
        }
        if(s[i] == '1' && t[i] == '0') {
            c10 ++;
            lol.pb(1);
        }
    }
    if(c01 != c10) cout<<-1;
    else {
        int mx = 0;
        int p = 0;
        int q = 0;
        for(auto x : lol) {
            if (x == 0) {
                p++;
                if(q > 0) q--;
            }
            else {
                q++;
                if(p > 0) p--;
            }
            mx = max(mx, p+q);
        }
        cout << mx;
    }
}