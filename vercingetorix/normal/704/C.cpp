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
    scanf("%d %d", &n, &m);
    vi a(m,0);
    int z = 0;
    vvpi e(m);
    forn(i,0,n) {
        int k;
        scanf("%d", &k);
        if (k == 1) {
            int x;
            scanf("%d", &x);
            if(x>0) {
                a[x-1] = 1 - a[x-1];
            }
            else {
                a[-x-1] = 1 - a[-x-1];
                z=1-z;
            }
        }
        else {
            int x,y;
            scanf("%d %d", &x, &y);
            if(abs(x)==abs(y)) {
                if(x == y) {
                    if(x>0) {
                        a[x-1] = 1 - a[x-1];
                    }
                    else {
                        a[-x-1] = 1 - a[-x-1];
                        z = 1-z;
                    }
                }
                else z = 1-z;
            }
            else {
                e[abs(x)-1].pb(mp(abs(y)-1,i));
                e[abs(y)-1].pb(mp(abs(x)-1,i));
                if(x > 0) a[abs(y)-1] = 1 - a[abs(y)-1];
                if(y > 0) a[abs(x)-1] = 1 - a[abs(x)-1];
                if(x<0 || y<0) z = 1 - z;
            }
        }
    }
    pll ans = {1,0};
    if(z == 1) ans = {0,1};
    vi u(m,0);
    forn(i,0,m) {
        if(u[i] == 1) continue;
        if(e[i].size() == 0) {
            if(a[i]) {
                ans.first = (ans.first+ans.second)%mod;
                ans.second = ans.first;
            }
            else {
                ans.first = (2*ans.first)%mod;
                ans.second = (2*ans.second)%mod;
            }
            u[i] = 1;
            continue;
        }
        int cur = i;
        int prev = -1;
        int fe = -1;
        vi cycle(1,cur);
        while(1) {
            if(u[cur]) break;
            u[cur] = 1;
            for(auto pp : e[cur]) {
                if(pp.second == prev) continue;
                cycle.pb(pp.first);
                prev = pp.second;
                if(fe<0) fe = prev;
                cur = pp.first;
                break;
            }
        }
        int st = cycle[0];
        int en = cycle.back();
        if(st!=en) {
            reverse(all(cycle));
            cur = cycle.back();
            prev= fe;
            u[cur] = 0;
            while(1) {
                if(u[cur]) break;
                u[cur] = 1;
                for(auto pp : e[cur]) {
                    if(pp.second == prev) continue;
                    cycle.pb(pp.first);
                    prev = pp.second;
                    if(fe<0) fe = prev;
                    cur = pp.first;
                    break;
                }
            }
            st = cycle[0];
            en = cycle.back();
        }
        pll cool;
//        forn(kk,0,2) forn(rr,0,2) d[kk][rr] = 0;
        if(st != en) {
            vvll d(2,vll(2,0));
            if(a[st]) {
                d[0][0]++;
                d[1][1]++;
            }
            else {
                d[1][0]++;
                d[0][0]++;
            }
            forn(k,1,cycle.size()) {
                vvll d2(2,vll(2,0));
//                forn(kk,0,2) forn(rr,0,2) d2[kk][rr] = 0;
                d2[0][0] = (d[0][0] + d[1][0]) % mod;
                d2[0][1] = (d[0][1] + d[1][1]) % mod;
                d2[1][0] = (d[1][1] + d[0][0]) % mod;
                d2[1][1] = (d[1][0] + d[0][1]) % mod;
                if(a[cycle[k]]) {
                    swap(d2[1][0], d2[1][1]);
                }
                d = d2;
            }
            cool.first = (d[0][0]+d[1][0])%mod;
            cool.second= (d[0][1]+d[1][1])%mod;
        }
        else {
            cool = {0,0};
            vvll d(2,vll(2,0));
            d[0][0]++;
            forn(k,1,cycle.size()) {
                vvll d2(2,vll(2,0));
                d2[0][0] = (d[0][0] + d[1][0]) % mod;
                d2[0][1] = (d[0][1] + d[1][1]) % mod;
                d2[1][0] = (d[1][1] + d[0][0]) % mod;
                d2[1][1] = (d[1][0] + d[0][1]) % mod;
                if(a[cycle[k]]) {
                    swap(d2[1][0], d2[1][1]);
                }
                d = d2;
            }
            cool.first = d[0][0];
            cool.second= d[0][1];
            
            d= vvll(2,vll(2,0));
//            if(a[st]) {
//                d[1][1]++;
//            }
//            else {
//                d[1][0]++;
//            }
            d[1][0]++;
            forn(k,1,cycle.size()) {
                vvll d2(2,vll(2,0));
                d2[0][0] = (d[0][0] + d[1][0]) % mod;
                d2[0][1] = (d[0][1] + d[1][1]) % mod;
                d2[1][0] = (d[1][1] + d[0][0]) % mod;
                d2[1][1] = (d[1][0] + d[0][1]) % mod;
                if(a[cycle[k]]) {
                    swap(d2[1][0], d2[1][1]);
                }
                d = d2;
            }
            cool.first = (cool.first+d[1][0])%mod;
            cool.second= (cool.second+d[1][1])%mod;
        }
        pll ans2;
        ans2.first = (ans.first*cool.first + ans.second*cool.second)%mod;
        ans2.second = (ans.second*cool.first + ans.first*cool.second)%mod;
        ans = ans2;
    }

    
    
    
    cout<<ans.second;
    
    
    
    
    
    return 0;
//    vector<vector<pair<pi, int>>> e(m+1);
//    forn(i,0,n) {
//        int k;
//        scanf("%d", &k);
//        if (k == 1) {
//            int x;
//            scanf("%d", &x);
//            if(x>0) {
//                if(a[x] == -1) {
//                    cout<<0;
//                    return 0;
//                }
//                else a[x] = 1;
//            }
//            else {
//                if(a[-x] == 1) {
//                    cout<<0;
//                    return 0;
//                }
//                else a[x] = -1;
//            }
//        }
//        else {
//            int x,y;
//            scanf("%d %d", &x, &y);
//            if(abs(x)==abs(y)) {
//                if(x == y) {
//                    if(x>0) {
//                        if(a[x] == -1) {
//                            cout<<0;
//                            return 0;
//                        }
//                        else a[x] = 1;
//                    }
//                    else {
//                        if(a[-x] == 1) {
//                            cout<<0;
//                            return 0;
//                        }
//                        else a[x] = -1;
//                    }
//                }
//            }
//            else {
//                e[abs(x)].pb(mp(mp(x,y), i));
//                e[abs(y)].pb(mp(mp(y,x), i));
//            }
//        }
//    }
//    
//    vi u(n+1,0);
//    ll ans = 1;
//    forn(i,1,n+1) {
//        if(u[i] == 1) continue;
//        if(e[i].size() == 0) {
//            ans=(2*ans)%mod;
//            u[i] = 1;
//            continue;
//        }
//        int cur = i;
//        int prev = -1;
//        int fe = -1;
//        vpi cycle;
//        while(1) {
//            if(u[cur]) break;
//            u[cur] = 1;
//            for(auto pp : e[cur]) {
//                if(pp.second == prev) continue;
//                cycle.pb(pp.first);
//                prev = pp.second;
//                if(fe<0) fe = prev;
//                cur = abs(pp.first.second);
//                break;
//            }
//        }
//        int st = abs(cycle[0].first);
//        int en = abs(cycle.back().second);
//        if(st!=en) {
//            reverse(all(cycle));
//            for(auto & x : cycle) swap(x.first, x.second);
//            cur = abs(cycle.back().second);
//            prev= fe;
//            u[cur] = 0;
//            while(1) {
//                if(u[cur]) break;
//                u[cur] = 1;
//                for(auto pp : e[cur]) {
//                    if(pp.second == prev) continue;
//                    cycle.pb(pp.first);
//                    prev = pp.second;
//                    if(fe<0) fe = prev;
//                    cur = abs(pp.first.second);
//                    break;
//                }
//            }
//            st = abs(cycle[0].first);
//            en = abs(cycle.back().second);
//        }
//        if(st!=en) {
//            pll d = {1,1};
//            for(auto pp : cycle) {
//                pll d2;
//                
//                int f1 = pp.first/abs(pp.first);
//                int f2 = pp.second/abs(pp.second);
//                int num = abs(pp.first);
//                if(a[num] == 1) d.second = 0;
//                else if(a[num] == -1) d.first = 0;
//                d2.first = d.first+d.second;
//                d2.second = d.first+d.second;
//                if(f1>0 && f2>0) d2.second-=d.second;
//                else if(f1>0 && f2<0) d2.first-=d.second;
//                else if(f1<0 && f2>0) d2.second-=d.first;
//                else if(f1<0 && f2<0) d2.first-=d.first;
//                d = d2;
//            }
//            if(a[en] == 1) d.second = 0;
//            else if(a[en] == -1) d.first = 0;
//            ans = (ans * (d.first+d.second)) % mod;
//        }
//        else {
//            ll wa = 0;
//            pll d = {1,0};
//            for(auto pp : cycle) {
//                pll d2;
//                int f1 = pp.first/abs(pp.first);
//                int f2 = pp.second/abs(pp.second);
//                int num = abs(pp.first);
//                if(a[num] == 1) d.second = 0;
//                else if(a[num] == -1) d.first = 0;
//                d2.first = d.first+d.second;
//                d2.second = d.first+d.second;
//                if(f1>0 && f2>0) d2.second-=d.second;
//                else if(f1>0 && f2<0) d2.first-=d.second;
//                else if(f1<0 && f2>0) d2.second-=d.first;
//                else if(f1<0 && f2<0) d2.first-=d.first;
//                d = d2;
//            }
//            wa += d.first;
//            d = {0,1};
//            for(auto pp : cycle) {
//                pll d2;
//                int f1 = pp.first/abs(pp.first);
//                int f2 = pp.second/abs(pp.second);
//                int num = abs(pp.first);
//                if(a[num] == 1) d.second = 0;
//                else if(a[num] == -1) d.first = 0;
//                d2.first = d.first+d.second;
//                d2.second = d.first+d.second;
//                if(f1>0 && f2>0) d2.second-=d.second;
//                else if(f1>0 && f2<0) d2.first-=d.second;
//                else if(f1<0 && f2>0) d2.second-=d.first;
//                else if(f1<0 && f2<0) d2.first-=d.first;
//                d = d2;
//            }
//            wa += d.second;
//            ans = (ans * wa) % mod;
//        }
//    }
//    cout << ans;
//    
}