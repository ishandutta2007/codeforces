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
    int n;
    scanf("%d\n", &n);
    vpi r;
    vpi b;
    forn(i,0,n) {
        char c;
        int rc,bc;
        scanf("%c %d %d\n", &c, &rc, &bc);
        if(c=='B') b.pb(mp(rc,bc));
        else r.pb(mp(rc,bc));
    }
    if(r.size() > b.size()) {
        swap(r,b);
        forn(i,0,r.size()) swap(r[i].first, r[i].second);
        forn(i,0,b.size()) swap(b[i].first, b[i].second);
    }
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    int rnum = r.size();
    int bnum = b.size();
    int rcost = 0;
    int bcost = 0;
    if(rnum >= 0) {
        if(!r.empty())
        forn(i,0,r.size()) {
            if(r[i].first > rnum) {
                rcost += r[i].first-rnum;
                r[i].first = rnum;
            }
        }
        forn(i,0,b.size()) {
            if(b[i].first > rnum) {
                rcost += b[i].first-rnum;
                b[i].first = rnum;
            }
        }
    }
    int maxr = n*rnum;
    vvi d(d2[n], vi(maxr+1, 1000000000));
    d[0][0] = 0;
    forn(mask, 0, d2[n]-1) {
        int cb = 0;
        int cr = 0;
        forn(bit,0,n) {
            if(mask & d2[bit]) {
                if(bit<rnum) cr++;
                else cb++;
            }
        }
        forn(bit,0,n) {
            if(mask&d2[bit]) continue;
            pi cost;
            if(bit<rnum) cost = r[bit];
            else cost = b[bit-rnum];
            int ar = max(0, cost.first - cr);
            int ab = max(0, cost.second - cb);
            int nmask = mask | d2[bit];
            forn(sum,0,maxr-ar+1) {
                d[nmask][sum + ar] = min(d[nmask][sum+ar], d[mask][sum] + ab);
            }
        }
    }
    int rans = 2000000000;
    forn(sum,0,maxr+1) {
        int tr = rcost + sum;
        int tb = d[d2[n]-1][sum];
        int cand = n + max(tr, tb);
        rans = min(rans,cand);
    }
    cout<<rans;
    
}