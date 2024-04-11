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
const int LIMIT = 1000000;
int ban[LIMIT+1];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int t;
    read(t);
    forn(it,0,t) {
        forn(i,0,LIMIT+1) ban[i] = 0;
        int n;
        read(n);
        readv(a,n);
        vi da;
        forn(i,0,n) forn(j,i+1,n) {
            da.pb(abs(a[i]-a[j]));
        }
        sort(all(da));
        vi ans;
        int pt = 1;
        while(ans.size()<n) {
            while(ban[pt]) pt++;
            ans.pb(pt);
            ban[pt] = 1;
            for(auto x : da) {
                if(pt+x > LIMIT) break;
                ban[pt+x] = 1;
            }
        }
        printf("YES\n");
        forn(i,0,n) printf("%d ", ans[i]);
        printf("\n");
    }

    
    
}