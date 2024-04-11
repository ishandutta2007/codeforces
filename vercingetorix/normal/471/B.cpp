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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    cin>>n;
    vpi del;
    forn(i,0,n) {
        int a;
        cin>>a;
        del.pb(mp(a,i+1));
    }
    sort(all(del));
    vi r;
    forn(i,0,n-1) {
        if(del[i].first==del[i+1].first) r.pb(i);
    }
    if(r.size()<=1) cout<<"NO";
    else {
        vvi ans(3, vi(n));
        forn(ad,0,3) forn(i,0,n) ans[ad][i]=del[i].second;
        swap(ans[1][r[0]], ans[1][r[0]+1]);
        swap(ans[2][r[1]], ans[2][r[1]+1]);
        cout<<"YES"<<endl;
        forn(ad,0,3) {
            
            forn(i,0,n) {
                cout<<ans[ad][i]<<" ";
            }
            cout<<endl;
        }
    }
    
    // cout<<ans;
}