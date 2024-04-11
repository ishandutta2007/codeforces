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
    int n,p;
    scanf("%d %d", &n, &p);
    vi cnt(n,0);
    map<pi,int> pr;
    vpi vote;
    forn(i,0,n) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if(y>x) swap(x,y);
        vote.pb(mp(x,y));
        cnt[x]++;
        cnt[y]++;
        pr[mp(x,y)]++;
        pr[mp(y,x)]++;
    }
    ll ans = 0;
    vi s;
    forn(i,0,n) s.pb(cnt[i]);
    sort(all(s));
    forn(i,0,n) {
        int left = p - s[i];
        int u = lower_bound(all(s), left) - s.begin();
        int pairs = n-u;
        if(2*s[i] >= p) pairs--;
        ans += pairs;
    }
    ans /= 2;
    sort(all(vote));
    forn(i,0,n) {
        if(i>0 && vote[i] == vote[i-1]) continue;
        int x= vote[i].first;
        int y= vote[i].second;
        if(cnt[x]+cnt[y]>=p) {
            if(cnt[x]+cnt[y] - pr[vote[i]] < p) ans--;
        }
    }
    cout<<ans;
}