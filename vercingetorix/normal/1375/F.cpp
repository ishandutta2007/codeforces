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
    vll x(4);
    cin>>x[1]>>x[2]>>x[3];
    printf("First\n");
    ll a =2*(x[1]+x[2]+x[3]);
    printf("%lld\n", a);
    fflush(stdout);
    int i;
    scanf("%d", &i);
    x[i] += a;
    ll b = x[i]*3-x[1]-x[2]-x[3];
    printf("%lld\n", b);
    fflush(stdout);
    int j;
    scanf("%d", &j);
    x[j] += b;
    int j1 = j+1;
    int j2 = j+2;
    if(j1 > 3) j1-=3;
    if(j2 > 3) j2-=3;
    ll c = x[j] - max(x[j1], x[j2]);
    printf("%lld\n", c);
    fflush(stdout);
    
}