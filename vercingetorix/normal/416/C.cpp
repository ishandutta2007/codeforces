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
    int n;
    cin >> n;
    vector<pair<pi,int>> q;
    forn(i,0,n) {
        int c,p;
        cin>>c>>p;
        q.pb(mp(mp(p,-c),i+1));
    }
    sort(all(q));
    reverse(all(q));
    int k;
    vpi t;
    cin>>k;
    forn(i,0,k) {
        int p;
        cin>>p;
        t.pb(mp(p,i+1));
    }
    sort(all(t));
    vi occ(k+1,0);
    vpi ans;
    int money = 0;
    for(auto x : q) {
        for(auto y: t) {
            if (!occ[y.second] && (-x.first.second) <= y.first) {
                money+=x.first.first;
                ans.pb(mp(x.second, y.second));
                occ[y.second] = 1;
                break;
            }
        }
    }
    cout<<ans.size()<<" "<<money<<endl;
    for(auto x : ans) cout<<x.first<<" "<<x.second<<endl;
}