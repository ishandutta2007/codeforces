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
    int n,m,p;
    scanf("%d %d %d", &n, &m, &p);
    if((ll)(m-1) * (ll)p > 4*n+10) {
        cout<<0;
        return 0;
    }
    vi a(n);
    vi b(m);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,m) scanf("%d", &b[i]);
    vi ans;
    forn(s, 0, p) {
        int st = s;
        int en = st + (m-1)*p;
        if(en>=n) break;
        int w = 0;
        map<int, int> cnt;
        forn(i,0,m) {
            cnt[b[i]]++;
        }
        for(int i =st; i<=en; i+=p) {
            cnt[a[i]]--;
        }
        for(auto u : cnt) {
            if(u.second!=0) w++;
        }
        while(1) {
            if(w==0) ans.pb(st+1);
            if(cnt[a[st]] == 0) w++;
            cnt[a[st]]++;
            if(cnt[a[st]] == 0) w--;
            st+=p;
            en+=p;
            if(en>=n) break;
            if(cnt[a[en]] == 0) w++;
            cnt[a[en]]--;
            if(cnt[a[en]] == 0) w--;
        }
    }
    sort(all(ans));
    printf("%d\n", ans.size());
    for(auto u: ans) printf("%d ", u);
    
}