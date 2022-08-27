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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vll a(3);
    cin>>a[0]>>a[1]>>a[2];
    if(a[0]<2 && a[1]<2 &&a[2]<2) {
        cout<<0;
        return 0;
    }
    ll ans = 3ll*1e18;
    forn(i,0,4) {
        forn(j,0,4) {
            ll m = 0;
            ll b = 0;
            ll d = 0;
            ll s=  0;
            if(i==0) {
                b++;
                d++;
                s++;
            }
            else if(i==1) {
                d++;
                s++;
            }
            else if(i==2) s++;
            if(j==3) {
                b++;
                d++;
                s++;
            }
            else if(j==2) {
                d++;
                b++;
            }
            else if(j==1) b++;
            m = max(m, a[0]-b);
            m = max(m, a[1]-d);
            m = max(m, a[2]-s);
            ll tr = 3ll*m + j + 3-i;
            ans = min(ans, tr-a[0]-a[1]-a[2]);
        }
    }
    cout<<ans;
}