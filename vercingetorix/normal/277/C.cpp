#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    map<int, vpi> h,v;
    map<int, int> hb, vb;
    forn(i,0,k) {
        int x1,y1,x2,y2;
        scanf("%d %d %d %d", &x1, &y1,&x2, &y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x1==x2) {
            v[x1].pb(mp(y1,y2));
            vb[x1] = 1;
        }
        else {
            h[y1].pb(mp(x1,x2));
            hb[y2] = 1;
        }
    }
    vi gr;
    vi lol;
    vi ind;
    vector<char> dir;

    int cur = 0;
    int vleft = n-1-v.size();
    if(vleft > 0) {
        forn(i,1,n) if(vb[i] == 0) {
            gr.pb(m);
            ind.pb(i);
            dir.pb('V');
            break;
        }
        if(vleft%2) cur^=m;
    }
    int hleft = m-1-h.size();
    if(hleft > 0) {
        forn(i,1,m) if(hb[i] == 0) {
            gr.pb(n);
            ind.pb(i);
            dir.pb('H');
            break;
        }
        if(hleft%2) cur^=n;
    }
    for(auto it : v) {
        vpi ev;
        int last = 0;
        int op = 0;
        ev.pb(mp(m,0));
        for(auto x : it.second) {
            ev.pb(mp(x.first, 1));
            ev.pb(mp(x.second, -1));
        }
        sort(all(ev));
        int len = 0;
        for(auto x : ev) {
            if(op == 0) len+=x.first-last;
            op += x.second;
            last = x.first;
        }
        gr.pb(len);
        ind.pb(it.first);
        dir.pb('V');
        cur^=len;
    }
    for(auto it : h) {
        vpi ev;
        int last = 0;
        int op = 0;
        ev.pb(mp(n,0));
        for(auto x : it.second) {
            ev.pb(mp(x.first, 1));
            ev.pb(mp(x.second, -1));
        }
        sort(all(ev));
        int len = 0;
        for(auto x : ev) {
            if(op == 0) len+=x.first-last;
            op += x.second;
            last = x.first;
        }
        gr.pb(len);
        ind.pb(it.first);
        dir.pb('H');
        cur^=len;
    }
    if(cur == 0) cout<<"SECOND";
    else {
        printf("FIRST\n");
        vi ans(4,0);
        int from = 0;
        vpi ev;
        ev.pb(mp(0,0));
        int cut=0;
        forn(i,0,gr.size()) {
            if((gr[i]^cur) < gr[i]) {
                cut = gr[i] - (gr[i]^cur);
                if(dir[i] == 'V') from = 1;
                ans[1-from] = ind[i];
                ans[3-from] = ind[i];
                from += 2;
                if(dir[i] == 'V') {
                    ev.pb(mp(m,0));
                    for(auto x : v[ind[i]]) {
                        ev.pb(mp(x.first, 1));
                        ev.pb(mp(x.second, -1));
                    }
                }
                else {
                    ev.pb(mp(n,0));
                    for(auto x : h[ind[i]]) {
                        ev.pb(mp(x.first, 1));
                        ev.pb(mp(x.second, -1));
                    }
                }
                break;
            }
        }
        sort(all(ev));
        int len = 0;
        int op = 0;
        int last = 0;
        for(auto x : ev) {
            if(op == 0) {
                if(len+x.first-last >= cut) {
                    last += cut - len;
                    break;
                }
                len+=x.first-last;
                
            }
            op += x.second;
            last = x.first;
        }
        ans[from] = last;
        forn(i,0,4) printf("%d ", ans[i]);

    }
}