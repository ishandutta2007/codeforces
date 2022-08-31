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
//    int n;
    vi a;
    int d = 1;
    forn(i,0,8) {
        a.pb(d);
        d*=7;
    }
    int n,m;
    cin >> n>> m;
//    cout<<a.back();
    if(m>=a.back() || n>=a.back()) {
        cout << 0;
        return 0;
    }
    int m1 = lower_bound(all(a), m) - a.begin();
    int n1 = lower_bound(all(a), n) - a.begin();
    if(n==1) n1 = 1;
    if(m==1) m1 = 1;
//    cout<<n1;
    if(m1+n1 > 7) {
        cout<<0;
        return 0;
    }
    vi used(10000000, 0);
    int ans = 0;
    forn(i,0,a[m1+n1]) {
        vi u(7,0);
        int x = i;
        bool f=true;
        forn(j,0,m1+n1) {
            if(u[x%7]) {
                f=false;
                break;
            }
            u[x%7]=1;
            x/=7;
        }
        if(!f)continue;
        int h = i/a[m1];
        int mi = i%a[m1];
        if(h<n && mi<m) ans++;
    }
    cout<<ans;
}