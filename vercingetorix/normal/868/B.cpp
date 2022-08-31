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
    int h,m,s,t1,t2;
    cin>>h>>m>>s>>t1>>t2;
    h*=5;
    h%=60;
    t1*=5;
    t2*=5;
    t1%=60;
    t2%=60;
    vi occ(60,0);
    occ[h] = 1;
    occ[m] = 1;
    occ[s] = 1;
    int cur = t1;
    while(1) {
        if(cur==t2) {
            cout<<"YES";
            return 0;
        }
        if(occ[cur]) break;
        cur++;
        if(cur==60) cur = 0;
    }
    cur = t2;
    while(1) {
        if(cur==t1) {
            cout<<"YES";
            return 0;
        }
        if(occ[cur]) break;
        cur++;
        if(cur==60) cur = 0;
    }
    cout<<"NO";
    
}