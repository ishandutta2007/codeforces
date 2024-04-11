#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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
    int n,m,k;
    //string s;
    ll ans = 1;
    //cin >> n;
    scanf("%d %d\n", &n, &k);
    string s;
    getline(cin, s);
    //int best = 0;
    //ll bestadd = 1;
    vll add(k, 1);
    vi order;
    forn(i,0,k) order.pb(i);
    for(auto x:s) {
        int ind = (int) (x-'a');
        ans = (ans + add[ind]) %mod;
        for(int i = 0; i<k; i++) if(i!=ind) add[i]=(add[i]+add[ind]) % mod;
        vi neworder;
        neworder.pb(ind);
        for(auto x:order) if(x!=ind) neworder.pb(x);
        order = neworder;
    }
    for(int i = 0; i<n; i++) {
        int best=order.back();
        ans = (ans + add[best]) %mod;
        for(int i = 0; i<k; i++) if(i!=best) add[i]=(add[i]+add[best]) % mod;
        vi neworder;
        neworder.pb(best);
        for(auto x:order) if(x!=best) neworder.pb(x);
        order = neworder;
    }
    
    cout<<ans;
}