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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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
    int  t=1;
//    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vvi ans(n);
        forn(i,0,n) ans[i].pb(i);
        int last23 = n;
        vi ones;
        int can = 1;
        for(int i = n-1; i >=0; i--) {
            if(a[i] == 0) ans[i].clear();
            else if(a[i] == 1) ones.pb(i);
            else if(a[i] == 2) {
                if(ones.empty()) can = 0;
                else {
                    int v = ones.back();
                    ones.pop_back();
                    ans[v].clear();
                    ans[i].pb(v);
                    last23 = i;
                }
            }
            else {
                if(last23 != n) ans[i].pb(last23);
                else if(ones.size() > 0) {
                    int v = ones.back();
                    ones.pop_back();
                    ans[i].pb(v);
                }
                else can = 0;
                last23 = i;
            }
        }
        if(can == 0) printf("-1\n");
        else {
            int sum = 0 ;
            forn(i,0,n) sum += ans[i].size();
            printf("%d\n", sum);
            forn(i,0,n) for(auto x : ans[i]) {
                printf("%d %d\n", i+1, x+1);
            }
        }
    }
    
}