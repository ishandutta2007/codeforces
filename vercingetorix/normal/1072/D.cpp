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
    int n,k;
    scanf("%d %d\n", &n, &k);
    vs a(n);
    forn(i,0,n) getline(cin, a[i]);
    const int inf = 4*n*n;
    vvi na(n, vi(n, inf));
    if(a[0][0] == 'a') na[0][0] = 0;
    else na[0][0] = 1;
    forn(i,0,n) forn(j,0,n) {
        if(i==0 && j==0) continue;
        if(a[i][j] == 'a') {
            if(j>0) na[i][j] = min(na[i][j], na[i][j-1]);
            if(i>0) na[i][j] = min(na[i][j], na[i-1][j]);
        }
        else {
            if(j>0) na[i][j] = min(na[i][j], 1+na[i][j-1]);
            if(i>0) na[i][j] = min(na[i][j], 1+na[i-1][j]);
        }
    }
    vpi ba;
    forn(i,0,n) forn(j,0,n) {
        if(i==0 && j==0) ba.pb(mp(i,j));
        else if(na[i][j] > k) continue;
        else {
            if(ba[0].first + ba[0].second < i+j) {
                ba.clear();
                ba.pb(mp(i,j));
            }
            else if(ba[0].first + ba[0].second == i+j) {
                ba.pb(mp(i,j));
            }
        }
    }
    string ans = string(ba[0].first + ba[0].second + 1, 'a');
    if(k==0 && a[0][0] != 'a') ans = string(1, a[0][0]);
    while(ba[0].first + ba[0].second < 2*n-2) {
        char bc = 'z';
        map<pi, int> nb;
        for(auto x : ba) {
            forn(u,0,2) {
                int i = x.first;
                int j = x.second;
                if(u==0) i++;
                else j++;
                if(i>=n || j>=n) continue;
                if(a[i][j] < bc) {
                    bc = a[i][j];
                    nb.clear();
                    nb[mp(i,j)] = 1;
                }
                else if(a[i][j] == bc) nb[mp(i,j)] = 1;
            }
        }
        ans.pb(bc);
        ba.clear();
        for(auto x : nb) if(x.second == 1) ba.pb(x.first);
    }
    
    cout<<ans;
}