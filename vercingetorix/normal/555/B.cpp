#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;
ll mll = 1000000000000000005;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

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
    //for(int i=0; i<n; i++) 
    vpll isl;
    set<pll> bridges;
    ll l, r;
    fo(i,0,n){
        cin>>l>>r;
        isl.pb(mp(l,r));
    }
    fo(i, 0, m) {
        ll b;
        cin>>b;
        bridges.insert(mp(b,i+1));
    }
    bridges.insert(mp(0, 0));
    bridges.insert(mp(mll, 0));
    vector<pair<pll,int>> sb; // {maxpos, minpos}
    vi ans(n);
    fo(i,1,n) {
        sb.pb(mp(mp(isl[i].second-isl[i-1].first, isl[i].first-isl[i-1].second), i));
    }
    sort(all(sb));
    fo(i,0,n-1) {
        auto a=bridges.lower_bound(mp(sb[i].first.second,0));
        if(a->first > sb[i].first.first) {
            cout<<"No";
            return 0;
        }
        else {
            ans[sb[i].second] = a->second;
            bridges.erase(a);
        }
    }
    cout<<"Yes"<<endl;
    fo(i,1,n) cout<<ans[i]<<' ';
}