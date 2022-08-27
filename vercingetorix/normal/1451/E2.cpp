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

int req(string s, int i, int j) {
    printf("%s %d %d\n", s.c_str(), i, j);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    scanf("%d", &n);
    vi a;
    forn(i,0,n-1) {
        a.pb(req("XOR",i+1,i+2));
    }
    vi s;
    int cur = 0;
    vi w(n,-1);
    w[0] = 0;
    vi ans(n);
    forn(i,0,n-1) {
        cur ^= a[i];
        if(w[cur] != -1) {
            // s[ind-1] = s[i+1] => a[ind]^a[i+1] = 0
            int j = w[cur];
            ans[0] = req("XOR", 1, i+2) ^ req("AND", i+2, j+1);
            break;
        }
        else if(w[cur^(n-1)] != -1) {
            // a[ind]^a[i+1] = n-1
            int j = w[cur^(n-1)];
            if(j == 0) {
                if(i == 0) {
                    ans[2] = req("AND", 3, 1) | req("AND", 3, 2);
                    ans[0] = ans[2] ^a[0]^a[1];
                }
                else {
                    ans[1] = req("AND", 2, 1) | req("AND", 2, i+2);
                    ans[0] = ans[1] ^ a[0];
                }
            }
            else ans[0] = req("AND", 1, j+1) | req("AND", 1, i+2);
            break;
        }
        w[cur] = i + 1;
    }
    forn(i,0,n-1) {
        ans[i+1] = ans[i] ^ a[i];
    }
    printf("!");
    forn(i,0,n) printf(" %d", ans[i]);
}