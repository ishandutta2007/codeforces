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
    scanf("%d\n",&n);
    char c[200009];
    scanf("%s",c);
    string s(c);
    ll z = 1;
    ll a = 0;
    ll ab = 0;
    ll abc = 0;
    forn(i,0,n) {
        if(s[i] == 'a') {
            a = (a + z)%mod;
        }
        if (s[i] == 'b') {
            ab = (ab + a)%mod;
        }
        if (s[i] == 'c') {
            abc = (abc + ab)%mod;
        }
        if (s[i] == '?') {
            abc = (3*abc + ab)%mod;
            ab = (3*ab + a)%mod;
            a = (3*a + z)%mod;
            z = (z*3) % mod;
        }
    }
    cout<<abc;
}