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
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

ll dx(ll x, int n) {
    ll res = 1;
    forn(i,0,n) res*=x;
    return res;
}

vi ban(10,0);

vvll cnk(27, vll(27, 0));

ll sel(ll n, ll gd) {
    if(n == 0) return 1;
    if(gd == 0) return 0;
    return cnk[n+gd-1][gd-1];
}

struct grpR {
    vi ob;
    int cnt;
    int m;
    ll count() {
        for(auto x : ob) if(ban[x]) return 0;
        int gd = 0;
        forn(i,m,10) if(ban[i] == 0) gd++;
        return sel(cnt, gd);
    }
};

struct grpL {
    vi ob;
    int cnt;
    int m;
    ll count() {
        for(auto x : ob) if(ban[x]) return 0;
        int gd = 0;
        forn(i,0,m+1) if(ban[i] == 0) gd++;
        return sel(cnt, gd);
    }
};

ll inter(grpR a, grpL b) {
    sort(all(a.ob));
    sort(all(b.ob));
    int pta = 0, ptb = 0;
    while(1) {
        if(pta == a.ob.size() && ptb == b.ob.size()) break;
        else if(pta == a.ob.size()) {
            int dig = b.ob[ptb++];
            if(ban[dig]) return 0;
            if(a.cnt == 0 || a.m > dig) return 0;
            a.cnt--;
        }
        else if(ptb == b.ob.size()) {
            int dig = a.ob[pta++];
            if(ban[dig]) return 0;
            if(b.cnt == 0 || b.m < dig) return 0;
            b.cnt--;
        }
        else if(a.ob[pta] == b.ob[ptb]) {
            int dig = a.ob[pta++];
            if(ban[dig]) return 0;
            ptb++;
        }
        else if(a.ob[pta] < b.ob[ptb]) {
            int dig = a.ob[pta++];
            if(ban[dig]) return 0;
            if(b.cnt == 0 || b.m < dig) return 0;
            b.cnt--;
        }
        else {
            int dig = b.ob[ptb++];
            if(ban[dig]) return 0;
            if(a.cnt == 0 || a.m > dig) return 0;
            a.cnt--;
        }
    }
    if(a.cnt != b.cnt) {
        cout<<"FUCK YOU\n";
    }
    int gd = 0;
    forn(i,a.m,b.m+1) if(ban[i] == 0) gd++;
    return sel(a.cnt, gd);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    forn(i,0,27) cnk[i][0] = 1;
    forn(i,1,27) {
        forn(j,1,i+1) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    ll l, r;
    cin>>l>>r;
    if(l==r) {
        cout<<1;
        return 0;
    }
    ll d10 = 1;
    forn(i,0,18) d10  *= 10;
    while(l/d10 == r/d10) {
        l -= (l/d10)*d10;
        r -= (r/d10)*d10;
        d10/=10;
    }
    vi dl, dr;
    while(d10 > 0) {
        dl.pb((l/d10)%10);
        dr.pb((r/d10)%10);
        d10 /= 10;
    }
    if(dl.size() == 1) {
        cout<<dr[0] - dl[0] + 1;
        return 0;
    }
    ll ans = 0;
    vi curdig;
    if(dr[0] > dl[0] + 1) {
        forn(i,dl[0]+1, dr[0]) ban[i] = 1;
        int have = dr[0] - dl[0] - 1;
        int k = dr.size();
        int fr = 10;
        while(have > 0) {
            ans += cnk[k+fr-2][fr-1];
            have--;
            fr--;
        }
    }
    curdig.pb(dr[0]);
    int pt = 1;
    int last = 0;
    int dig = dr.size();
    vector<grpR> allr;
    vector<grpL> alll;
    while(pt < dr.size()) {
        bool bad = false;
        while(pt < dr.size()) {
            if(dr[pt] < last) {
                bad = true;
                break;
            }
            else if(dr[pt] > last) break;
            curdig.pb(last);
            pt++;
        }
        if (bad) break;
        if (pt == dig) {
            allr.emplace_back();
            allr.back().ob = curdig;
            allr.back().cnt = 0;
            allr.back().m = 9;
        }
        else {
            while(last < dr[pt]) {
                allr.emplace_back();
                allr.back().ob = curdig;
                allr.back().ob.pb(last);
                allr.back().cnt = dig-pt-1;
                allr.back().m = last;
                last++;
            }
        }
    }
    pt = 1;
    curdig.clear();
    curdig.pb(dl[0]);
    last = 9;
    while(pt < dl.size()) {
        bool bad = false;
        while(pt < dl.size()) {
            if(dl[pt] > last) {
                bad = true;
                break;
            }
            else if(dl[pt] < last) break;
            curdig.pb(last);
            pt++;
        }
        if (bad) break;
        if (pt == dig) {
            alll.emplace_back();
            alll.back().ob = curdig;
            alll.back().cnt = 0;
            alll.back().m = 9;
        }
        else {
            while(last > dl[pt]) {
                alll.emplace_back();
                alll.back().ob = curdig;
                alll.back().ob.pb(last);
                alll.back().cnt = dig-pt-1;
                alll.back().m = last;
                last--;
            }
        }
    }
    for(auto x : alll) ans += x.count();
    for(auto x : allr) ans += x.count();
    for(auto x : allr) for(auto y : alll) ans -= inter(x, y);
    cout<<ans;
}