#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int A = 100500;
vpi g[A];
vi t[A];
ll depth = 0;
//vpll ev;
multiset<pll> ev;
vi add;
int need = 0;
const ll INF = 1e18;
ll bang = INF;

set<int> dfs(int v) {
    set<int> cur;
    set<pll> added;
    for(auto u : g[v]) {
        depth += u.second;
        set<int> ret = dfs(u.first);
        depth -= u.second;
        if(u == g[v].back()) ret.insert(-1);
        if(ret.size() > cur.size()) swap(ret, cur);
        for(auto x : ret) add.pb(x);
//        if(!ret.empty()) {
//            cout<<"UNITE ON "<<v<<":";
//            for(auto x : cur) cout<<' '<<x;
//            cout<<" AND";
//            for(auto x : ret) cout<<' '<<x;
//            cout<<'\n';
//        }
        int k = add.size();
        forn(i,0,k) {
            auto it = cur.lower_bound(add[i]);
            if(it != cur.end()) if(i+1 == k || add[i+1] > *it) if(depth+*it < bang) {
                need++;
                ll st = (add[i] == -1) ? -1 : depth + add[i];
//                ev.insert(mp(st, -1));
//                ev.insert(mp(depth + *it, 1));
                ev.insert(mp(st, depth+*it));
                ev.insert(mp(depth + *it, -1));
                added.insert(mp(st,depth+*it));
                if(it != cur.begin()) {
                    auto it2 = it;
                    it2--;
                    st = (*it2 == -1) ? -1 : depth+*it2;
                    ll en = depth+*it;
                    if(added.count(mp(st,en))) {
                        added.erase(mp(st,en));
                        ev.erase(ev.find(mp(st,en)));
                        ev.erase(ev.find(mp(en,-1)));
                        need--;
                    }
                }
            }
            if(it != cur.begin()) {
                it--;
                if(i > 0 && add[i-1] < *it) {
                    ll st = (add[i-1] == -1) ? -1 : depth + add[i-1];
                    ll en = depth + add[i];
                    if(added.count(mp(st,en))) {
                        added.erase(mp(st,en));
                        ev.erase(ev.find(mp(st,en)));
                        ev.erase(ev.find(mp(en,-1)));
                        need--;
                    }
                }
                if(i == 0 || add[i-1] < *it) if(depth + add[i] < bang) {
                    need++;
                    ll st = (*it == -1) ? -1 : depth + *it;
//                    ev.insert(mp(st, -1));
//                    ev.insert(mp(depth + add[i], 1));
                    ev.insert(mp(st, depth+add[i]));
                    ev.insert(mp(depth + add[i], -1));
                    added.insert(mp(st,depth+add[i]));
                }
            }
        }
        for(auto x : add) cur.insert(x);
        add.clear();
    }
    cur.erase(-1);
    for(auto x : t[v]) cur.insert(x);
    return cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,n-1) {
        int u,v,len;
        scanf("%d %d %d", &u, &v, &len);
        --u; --v;
        g[u].pb(mp(v, len));
    }
    forn(i,0,m) {
        int s,tc;
        scanf("%d %d", &s, &tc);
        tc--;
        s--;
        t[s].pb(tc);
    }
    dfs(0);
//    srt(ev);
//    for(auto x : ev) cout<<x.first<<' '<<x.second<<'\n';
    ll last = -1;
    ll done = 0;
    ll av = 0;
    multiset<ll> due;
    need = 0;
    for(auto x : ev) {
        ll el = x.first-last;
        while(el > 0 && !due.empty()) {
            due.erase(due.begin());
            el--;
        }
        last = x.first;
        if(x.second == -1 && !due.empty() && *due.begin() <= x.first) {
            bang = x.first;
            break;
        }
        else if(x.second != -1) {
            due.insert(x.second);
            need++;
        }
    }
//    for(auto x : ev) {
//        ll el = x.first - last;
//        done += min(av,el);
//        av -= min(av,el);
//        last = x.first;
//        if(x.second == -1) av++;
//        else {
//            if(done <= 0) {
//                bang = x.first;
//                break;
//            }
//            else done--;
//        }
//    }
    if(bang != INF) {
        need = 0;
        ev.clear();
        dfs(0);
        cout<<bang+1<<' '<<need<<'\n';
    }
    else {
        cout<<-1<<' '<<need<<'\n';
    }
    
    
}