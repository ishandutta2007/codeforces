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
    int n,m;
    cin>>n>>m;
    vi a(n);
    vvi cnt(3000);
    forn(i,0,n) {
        cin>>a[i];
        if(a[i] > m) cnt[0].pb(i);
        else cnt[a[i]].pb(i);
    }
    int mn = n/m;
    int p = 0;
    int ans = 0;
    forn(i,1,m+1) {
        while(cnt[i].size() < mn) {
            if(cnt[p].size()==0 || (p>=1 && p<=m && cnt[p].size()<=mn)) {
                p++;
                continue;
            }
            cnt[i].pb(cnt[p].back());
            a[cnt[p].back()] = i;
            cnt[p].pop_back();
            
            ans++;
        }
    }
    cout<<mn<<' '<<ans<<endl;
    forn(i,0,n) cout<<a[i]<<' ';
}