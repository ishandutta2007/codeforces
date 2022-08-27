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
    int t;
    read(t);
    forn(afaff,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vpi a;
        forn(i,0,m) {
            int x,y;
            scanf("%d %d", &x, &y);
            a.pb(mp(y,x));
        }
        sort(all(a));
        string ans = "YES\n";
        while(a.size() > 0) {
            if(a.size() == 1) {
                ans = "NO\n";
                break;
            }
            int n = a.size();
            if(n>1 && a[n-1].first == a[n-2].first) {
                a.pop_back();
                a.pop_back();
                continue;
            }
            else if(n>2 && a[n-3].first == a[n-2].first) {
                ans = "NO\n";
                break;
            }
            else {
                if((a[n-1].first - a[n-2].first + a[n-1].second + a[n-2].second)%2 == 1) {
                    a.pop_back();
                    a.pop_back();
                    continue;
                }
                else {
                    ans = "NO\n";
                    break;
                }
            }
        }
        printf("%s", ans.c_str());
        
        
    }
}