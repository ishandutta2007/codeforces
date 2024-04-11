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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    getline(cin, s);
    int n = s.size();
    vi has(10,0);
    int cnt = 0;
    for(auto x : s) {
        if(x == '?') cnt++;
        if(x>='A' && x<='J') has[x-'A'] = 1;
    }
    int lol = 0;
    forn(i,0,10) lol += has[i];
    ll ans = 1;
    if(lol > 0) {
        if(s[0]>='A' && s[0]<='J') {
            ans *= 9;
        }
        else ans*=10;
        lol--;
        forn(i,0,lol) ans*=(9-i);
    }
    if(s[0] == '?') {
        cnt--;
        ans*=9;
    }
    printf("%lld", ans);
    forn(i,0,cnt) printf("0");
    
}