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
    int n,m,d;
    scanf("%d %d %d", &n, &m, &d);
    vi a(n);
    forn(i,0,m) {
        int l;
        scanf("%d", &l);
        forn(j,0,l) {
            int x;
            scanf("%d", &x);
            a[x-1] = i;
        }
    }
    vi cnt(m,0);
    forn(i,0,d) {
        cnt[a[i]]++;
    }
    vi d2;
    int deg2=1;
    forn(i,0,21) {
        d2.pb(deg2);
        deg2*=2;
    }
    vi ban(d2[m], 0);
    int en = d-1;
    int st = 0;
    while(1) {
        int toban = 0;
        forn(i,0,m) {
            if(cnt[i] == 0) toban |= d2[i];
        }
        ban[toban] = 1;
        cnt[a[st]]--;
        st++;
        en++;
        if(en>=n) break;
        cnt[a[en]]++;
        
    }
    int ans = m;
    for(int i = d2[m]-1; i>=0; i--) {
        if(ban[i]) {
            forn(j,0,m) if(i & d2[j]) ban[i-d2[j]] = 1;
        }
        else {
            int c = 0;
            forn(j,0,m) if(i & d2[j]) c++;
            ans = min(ans, c);
        }
    }
    cout<<ans;
    
    
}