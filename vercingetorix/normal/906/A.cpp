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
    int n;
    scanf("%d\n", &n);
    char c[100100];
    char t;
    vi can(26,1);
    bool done = false;
    int ans = 0;
    forn(i,0,n-1) {
        scanf("%c %s\n", &t, c);
        string s(c);
        vi now(26,0);
        for(auto pt : s) now[pt-'a'] = 1;
        if(t == '.') {
            forn(j,0,26) if(now[j] == 1) can[j] = 0;
        }
        else if(t == '?') {
            if(done) ans++;
            can[s[0]-'a'] = 0;
        }
        else if(t=='!') {
            if(done) ans ++;
            forn(j,0,26) if(now[j] == 0)  can[j] = 0;
        }
        int sum = 0;
        forn(j,0,26) sum+=can[j];
        if(sum==1) done = true;
    }
    cout<<ans;
}