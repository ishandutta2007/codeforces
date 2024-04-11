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

int gr[4][101];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    gr[0][0] = 0;
    gr[0][1] = 1;
    gr[1][1] = 0;
    gr[2][0] = 0;
    gr[2][1] = 1;
    gr[3][0] = 0;
    gr[3][1] = 1;
    forn(l, 2, 101) {
        vi can = vi(200,0);
        forn(i,0,l) can[gr[0][i]^gr[0][l-1-i]] = 1;
        forn(i,1,l-1) can[gr[1][i]^gr[1][l-1-i]] = 1;
        forn(i,0,200) if(!can[i]) {
            gr[0][l] = i;
            break;
        }
        can = vi(200,0);
        forn(i,0,l-1) can[gr[0][i]^gr[1][l-1-i]] = 1;
        forn(i,0,200) if(!can[i]) {
            gr[1][l] = i;
            break;
        }
        can = vi(200,0);
        forn(i,0,l) can[gr[2][i]^gr[0][l-1-i]] = 1;
        forn(i,0,l-1) can[gr[2][i]^gr[1][l-1-i]] = 1;
        forn(i,0,200) if(!can[i]) {
            gr[2][l] = i;
            break;
        }
        can = vi(200,0);
        forn(i,0,l) can[gr[2][i]^gr[2][l-1-i]] = 1;
        forn(i,0,200) if(!can[i]) {
            gr[3][l] = i;
            break;
        }
    }
    int r,n;
    cin>>r>>n;
    if(n == 0) {
        if(gr[3][r] == 0) cout<<"LOSE";
        else cout<<"WIN";
        return 0;
    }
    vpi ya;
    forn(i,0,n) {
        int r,c;
        cin>>r>>c;
        ya.pb(mp(r,c));
    }
    sort(all(ya));
    int cur = 0;
    cur ^= gr[2][ya[0].first - 1];
    cur ^= gr[2][r-ya.back().first];
    forn(i,0,n-1) {
        if(ya[i].second == ya[i+1].second) cur ^= gr[0][ya[i+1].first - ya[i].first -1];
        else cur ^= gr[1][ya[i+1].first - ya[i].first -1];
    }
    if(cur == 0) cout<<"LOSE";
    else cout<<"WIN";
    
    
}