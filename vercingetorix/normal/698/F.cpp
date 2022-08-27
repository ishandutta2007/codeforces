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
    
    int n;
    scanf("%d", &n);
    vll nfac(n+1, 1);
    for(ll i=2; i<n+1; i++) nfac[i] = (nfac[i-1]*i)%mod;
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    vvi bucket(n+1);
    vpi wb(n+1);
    bucket[1].pb(1);
    wb[1] = mp(1,0);
    forn(i,2,n+1) {
        if(isp[i]) {
            int ni = n/i;
            wb[i] = mp(ni, bucket[ni].size());
            bucket[ni].pb(i);
            
        }
    }
    ll ans = 1;
    vi cnt(n+1,0);
    vi to(n+1);
    forn(i,1,n+1) {
        int k = i;
        int bu = 1;
        while(k>1) {
            int p = mindiv[k];
            bu*=p;
            k/=p;
            while(k%p==0) k/=p;
        }
        to[i] = bu;
        if(a[i-1] == 0) cnt[bu]++;
    }
    
    forn(i,1,n+1) {
        ans = (ans*nfac[cnt[i]]) % mod;
    }
    vvi lf(n+1);
    vvi lt(n+1);
    vvpi oto(n+1);
    forn(i,0,n) {
        if(a[i]==0) continue;
        vpi bifrom, bito;
        int k = to[i+1];
        if(k==1) bifrom.pb(wb[1]);
        while(k>1) {
            bifrom.pb(wb[mindiv[k]]);
            k/=mindiv[k];
        }
        k = to[a[i]];
        if(k==1) bito.pb(wb[1]);
        while(k>1) {
            bito.pb(wb[mindiv[k]]);
            k/=mindiv[k];
        }
        sort(all(bifrom));
        sort(all(bito));
        if(bifrom.size()!=bito.size()) {
            cout<<0;
            return 0;
        }
        forn(j,0,bifrom.size()) {
            if(bifrom[j].first != bito[j].first) {
                cout<<0;
                return 0;
            }
            oto[bifrom[j].first].pb(mp(bifrom[j].second, bito[j].second));
        }
    }
    forn(i,1, n+1) {
        if(bucket[i].size() > 1) {
            sort(all(oto[i]));
            vi used(bucket[i].size(), 0);
            int proc = 0;
            if(!oto[i].empty()) used[oto[i][0].second] = 1;
            forn(j,1, oto[i].size()) {
                if(oto[i][j] == oto[i][j-1]) continue;
                if(oto[i][j].first == oto[i][j-1].first) {
                    cout<<0;
                    return 0;
                }
                if(used[oto[i][j].second]) {
                    cout<<0;
                    return 0;
                }
                used[oto[i][j].second] = 1;
            }
            for(auto x : used) proc+=x;
            ans = (ans*nfac[(int)bucket[i].size()- proc]) % mod;
        }
    }
    cout<<ans;

    
}