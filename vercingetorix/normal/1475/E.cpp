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
    const int A = 1001;
    vvi cnk(A, vi(A, 0));
    cnk[0][0] = 1;
    forn(n,1,A) {
        cnk[n][0] = 1;
        forn(k,1,n+1) {
            cnk[n][k] = (cnk[n-1][k-1] + cnk[n-1][k])%mod;
        }
    }
    int t;
    read(t);
    forn(afaff,0,t) {
        int n,k;
        scanf("%d %d", &n, &k);
        readv(a,n);
        sort(all(a));
        reverse(all(a));
        vi taken(n+1,0);
        vi cnt(n+1,0);
        forn(i,0,k) taken[a[i]]++;
        forn(i,0,n) cnt[a[i]]++;
        cout<<cnk[cnt[a[k-1]]][taken[a[k-1]]]<<endl;
    }
    
}