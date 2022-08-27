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
    int nn,m;
    ll n;
    scanf("%d", &nn);
    n=nn;
    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    int k = n/2;
    vi cnt(n+1,0);
    vi cnthalf(n+1,0);
    int mine = n+1;
    int maxe = -1;
    forn(i,0,k) {
        if(a[i]!=a[n-1-i]) {
            maxe=max(maxe, i);
            mine=min(mine, i);
        }
        cnthalf[a[i]]++;
        cnt[a[i]]++;
    }
    if (maxe==-1) {
        ll nn = n;
        cout<< n*(n+1)/2;
        return 0;
    }
    forn(i,k,n) {
        cnt[a[i]]++;
    }
    bool halfcool = true;
    if(n&1) cnt[a[k]]--;
    forn(i,0,n+1) if(cnt[i]!=2*cnthalf[i]) halfcool=false;
    if(n&1) cnt[a[k]]++;
    int oddcnt = 0;
    forn(i,0,n+1) if(cnt[i]&1) oddcnt++;
    if(oddcnt > 1) {
        cout<<0; return 0 ;
    }
    if(n%2 == 0) if(oddcnt>0) {
        cout<<0; return 0 ;
    }
    if(halfcool) {
        ll l = mine;
        ll l1 = maxe;
        ll r1 = n-1-l1;
        ll r = n-1-l;
        cout<< (l+1)*(n-l1)+(r1+1)*(n-r) - (l+1)*(n-r);
        return 0;
    }
    else {
        ll l = mine;
        ll r = n-1-l;
        forn(i,0,l) cnt[a[i]]-=2;
        vi cntl(n+1,0);
        vi cntr(n+1,0);
        forn(i,0,n+1)cntl[i]=cnt[i];
        forn(i,0,n+1)cntr[i]=cnt[i];
        vb(n+1,false);
        int bl=0;
        forn(i,0,n+1) {
            if(cnt[i]) bl++;
        }
        int br = bl;
        ll lto = l-1;
        while(bl>0) {
            lto++;
            if (2*cntl[a[lto]]-2 <= cnt[a[lto]]) if (2*cntl[a[lto]] > cnt[a[lto]]) bl--;
            cntl[a[lto]]--;
        }
        ll rto = r+1;
        while(br>0) {
            rto--;
            if (2*cntr[a[rto]]-2 <= cnt[a[rto]]) if (2*cntr[a[rto]] > cnt[a[rto]]) br--;
            cntr[a[rto]]--;
        }
        cout<<(l+1)*(n-lto) + (rto+1)*(n-r) - (l+1)*(n-r);
    }
    
    //    int curl = 0;
    //    int curr = n-1;
    //    vi match(n+1, 0);
    //    forn(i,0,n+1)
    //    ll ans  =0;
    //    while(curl<n) {
    //
    //        curl++;
    //    }
    
    // cout<<ans;
}