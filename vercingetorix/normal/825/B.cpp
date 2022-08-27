#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vs a(10);
    forn(i,0,10) getline(cin, a[i]);
    vpi dir;
    dir.pb(mp(1,0));
    dir.pb(mp(0,1));
    dir.pb(mp(1,-1));
    dir.pb(mp(1,1));
    for(auto x : dir) {
        forn(i,0,10) forn(j,0,10) {
            int cx = 0;
            int cdot = 0;
            forn(s,0,5) {
                int ix = i+s*x.first;
                int iy = j+s*x.second;
                if(ix<10 && ix>=0 && iy<10 &&iy>=0) {
                    if(a[ix][iy] == 'X') cx++;
                    else if(a[ix][iy] == '.') cdot++;
                }
            }
            if(cx==4 && cdot==1) {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}