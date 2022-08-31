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
    int n,m;
    cin>>n>>m;
    vi a(n,100000000);
    vi ch(n,0);
    vvi op;
    forn(ia,0,m) {
        int t;
        cin>>t;
        if(t==1) {
            int l,r,d;
            cin>>l>>r>>d;
            op.pb(vi({t,l,r,d}));
            l--; r--;
            forn(i,l,r+1) ch[i] += d;
        }
        if(t==2) {
            int l,r,m;
            cin>>l>>r>>m;
            op.pb(vi({t,l,r,m}));
            l--;
            r--;
            forn(i,l,r+1) a[i] = min(a[i], m - ch[i]);
        }
    }
    vi ans = a;
    forn(ia,0,m) {
        int t;
        t=op[ia][0];
        if(t==1) {
            int l,r,d;
            l=op[ia][1];
            r=op[ia][2];
            d=op[ia][3];
            l--; r--;
            forn(i,l,r+1) a[i] += d;
        }
        if(t==2) {
            int l,r,m;
            l=op[ia][1];
            r=op[ia][2];
            m=op[ia][3];
            l--;r--;
            int cmax = -1000000000;
            forn(i,l,r+1) cmax = max(cmax, a[i]);
            if(cmax!=m) {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    forn(i,0,n) cout<<ans[i]<<" ";
}