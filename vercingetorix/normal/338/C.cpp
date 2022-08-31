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
int n;
vll a;
vll prlist2;
vll prlist;
vi par;
int ans = 1000000;
void test() {
    int host = 0;
    int cand = n;
    vll b = a;
    forn(i,0,n) {
        if(par[i] >= 0) {
            if(b[par[i]] % a[i] != 0) return;
            b[par[i]] /= a[i];
            if(b[par[i]] > 0) b[par[i]] = -b[par[i]];
        }
        else {
            host++;
        }
    }
    if(host > 1) cand++;
    forn(i,0,n) {
        int cnt = 0;
        for(auto pr:prlist) {
            while(b[i] % pr == 0) {
                b[i] /= pr;
                cnt++;
            }
        }
        if(cnt == 0) continue;
        else if(cnt==1) {
            if(b[i] == -1) cand++;
        }
        else {
            cand += cnt;
        }
    }
    ans = min(ans,cand);
}

void dp(int k) {
    if(k==n) {
        test();
    }
    else {
        forn(i,-1,k) {
            par[k] = i;
            dp(k+1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int LIMIT = 1000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    cin>>n;
    a.resize(n);
    par.resize(n);
    forn(i,0,n) {
        cin>>a[i];
        ll cur = a[i];
        for(auto pr :p) {
            while(cur % pr == 0) {
                prlist2.pb(pr);
                cur/=pr;
            }
        }
        if(cur > 1) prlist2.pb(cur);
    }
    sort(all(prlist2));
    forn(i,0, prlist2.size()) {
        if(i==0 || prlist2[i] != prlist2[i-1]) prlist.pb(prlist2[i]);
    }
    sort(all(a));
    reverse(all(a));
    dp(0);
    cout<<ans;
    
}