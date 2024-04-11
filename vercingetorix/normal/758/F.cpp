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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    const int LIMIT = 10000000;
//    vb isp(LIMIT+1, true);
//    vi mindiv(LIMIT+1, 0);
//    forn(i,0,LIMIT+1) mindiv[i]=i;
//    int upbound = (int)sqrt((double)LIMIT);
//    vi p;
//    for (int m = 2; m <= upbound; m++) {
//        if (isp[m]) {
//            p.pb(m);
//            for (int k = m * m; k <= LIMIT; k += m) {
//                isp[k] = false;
//                mindiv[k]=min(mindiv[k], m);
//            }
//        }
//    }
//    
//    for(int m = upbound+1; m<=LIMIT; m++) {
//        if (isp[m]) {
//            p.pb(m);
//        }
//    }
//    vvi degs(24);
//    forn(i,2,24) {
//        ll pt = 1;
//        ll cur = 0;
//        while(1) {
//            ll cand = 1;
//            forn(j,0,i) {
//                cand *= cur;
//                if(cand > 1e8) break;
//            }
//            if(cand > 1e8) break;
//            degs[i].pb(cand);
//            cur++;
//        }
//        sort(all(degs[i]));
//    }
    
    
    int n,l,r;
    cin>>n>>l>>r;

    if(n==1) {
        cout<<r-l+1;
        return 0;
    }
    if(n==2) {
        ll x = r-l+1;
        cout<<x*(x-1);
        return 0;
    }
    ll ans = 0;
    forn(p,1,4000) {
        ll dp = 1;
        forn(i,0,n-1) {
            dp*=p;
            if(dp > r) break;
        }
        if(dp > r) break;
        forn(q,1,4000) {
            if(p==q) continue;
            ll dq = 1;
            forn(i,0,n-1) {
                dq*=q;
                if(dq > r) break;
            }
            if(dq > r) break;
            if(gcd(p,q) > 1) continue;
            ll ls = max(((l + dq-1)/dq)*dq, ((l + dp-1)/dp)*dq);
            ll rs = min((r/dq)*dq, (r/dp)*dq);
            // cout<<p<<' '<<q<<" num "<<(rs-ls)/dq+1<<endl;
            if(rs >= ls) {ans += (rs-ls)/dq + 1;
                
            }
        }
    }
    cout<<ans;
//    forn(s,l,r+1) {
//        vi div;
//        int u = s;
//        while(u>1) {
//            div.pb(mindiv[u]);
//            u/=mindiv[u];
//        }
//        sort(all(div));
//        int pt = 0;
//        int sn = 1;
//        while(pt<div.size()) {
//            int pr = pt+1;
//            while(pr<div.size() && div[pr] == div[pt]) pr++;
//            if(pr-pt >= (n-1)) {
//                sn *= (pr-pt)/(n-1);
//            }
//            pt = pr;
//        }
//        for(int k = 1; k*k <= sn; k++) {
//            if(sn%k == 0) {
//                ll def = s / degs[n-1][k];
//            }
//        }
//    }
    
}