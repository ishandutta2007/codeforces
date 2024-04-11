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

map<int, int> pr[300000];


class stree {
public:
    vpi t;
    int s;
    pi combine(pi a, pi b) {
        return mp(max(a.first, b.first), max(max(a.second, b.second), min(a.first, b.first)));
    }
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = mp(a[tl],0);
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        if (pos == tl && tr == pos) {
            t[v] = mp(val,0);
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos, val);
            else set(v*2+1, tm+1, tr, pos, val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    
    pi get (int v, int tl, int tr, int l, int r) {
        if(l>r) return mp(0,0);
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};
vi ctoi;
vi lfori;
stree dj;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,c;
    scanf("%d %d", &n, &c);
    vi l(n), r(n), cost(n);
    vpi allcost;
    forn(i,0,n) scanf("%d %d %d", &l[i], &r[i], &cost[i]);
    if(n==0) {
        int m;
        scanf("%d", &m);
        vi q(m);
        forn(i,0,m) {
            scanf("%d", &q[i]);
            printf("%d\n", q[i]);
        }
        return 0;
    }
    vi def(n,0);
    dj.build(def, 1, 0, n-1);
    forn(i,0,n) allcost.pb(mp(cost[i], i));
    sort(all(allcost));
    ctoi.resize(n);
    forn(i,0,n) ctoi[allcost[i].second] = i;
    int re = n-1;
    lfori.resize(n);
    forn(le,0,n) {
        while(re>=0 && allcost[le].first + allcost[re].first > c) re--;
        lfori[le] = re;
    }
    vpi ev;
    forn(i,0,n) {
        ev.pb(mp(l[i], -i-1));
        ev.pb(mp(r[i], i+1));
    }
    int m;
    scanf("%d", &m);
    vi q(m);
    forn(i,0,m) scanf("%d", &q[i]);
    
    vi qs = q;
    int pq = 0;
    map<int, int> ans;
    sort(all(qs));
    const int INF = 1e9;
    ev.pb(mp(2*INF + 100, 0));
    sort(all(ev));
    const int A = 500;
    vvi nb(n);
    vi big(n,0);
    int last = 0;
    int fr = 0;
    multiset<int> op;
    int pt = 0;
    vi biglist;
    pi b2;
    int b2res = 0;
    vi sin(n,0);
    vi bestpair(n,0);
    vi bestpval(n,0);
    while(1) {
        if(pq == qs.size()) break;
        auto x = ev[pt];
        if(last == x.first) {
            if (x.second < 0) op.insert(-x.second-1);
            else op.erase(op.find(x.second-1));
            pt++;
            continue;
        }
        if (op.size() > 2) last = x.first;
        else if(op.size() == 2) {
            auto it = op.begin();
            int a = *it++;
            int b = *it;
            if(a>b) swap(a, b);
            if(cost[a] + cost[b] > c) {
                last = x.first;
                continue;
            }
            if(pr[a].find(b) == pr[a].end()) {
                nb[a].pb(b);
                nb[b].pb(a);
                pr[a][b] += x.first - last;
                pr[b][a] += x.first - last;
                if(nb[a].size() == A) {
                    for (auto x : pr[a]) {
                        int bt = x.first;
                        int abv = x.second;
                        if (bestpval[a] < abv + sin[bt] + sin[a]) {
                            bestpval[a] = abv + sin[bt] + sin[a];
                            bestpair[a] = bt;
                        }
                    }
                    big[a] = 1;
                    biglist.pb(a);
                }
                if(nb[b].size() == A) {
                    for (auto x : pr[b]) {
                        int at = x.first;
                        int abv = x.second;
                        if (bestpval[b] < abv + sin[b] + sin[at]) {
                            bestpval[b] = abv + sin[b] + sin[at];
                            bestpair[b] = at;
                        }
                    }
                    big[b] = 1;
                    biglist.pb(a);
                }
            } else {
                pr[a][b] += x.first - last;
                pr[b][a] += x.first - last;
            }
            int cand = fr + sin[a] + sin[b] + pr[a][b];
            if (cand - fr > b2res) {
                b2 = mp(a,b);
                b2res = cand - fr;
            }
            while(pq != qs.size() && qs[pq] <= cand) {
                ans[qs[pq]] = x.first - cand + qs[pq];
                pq++;
            }
            last = x.first;
        }
        else if(op.size() == 0) {
            fr += x.first - last;
            while(pq != qs.size() && qs[pq] <= fr + b2res) {
                ans[qs[pq]] = x.first - fr - b2res + qs[pq];
                pq++;
            }
            last = x.first;
        }
        else {
            int a = *op.begin();
            if(cost[a] > c) {
                last = x.first;
                continue;
            }
            sin[a] += x.first - last;
            int ind = ctoi[a];
            int lind = lfori[ind];
            dj.set(1, 0, n-1, ind, sin[a]);
            pi res = dj.get(1, 0, n-1, 0, lind);
//            testdisjoint();
            
            if(ind <= lind && res.first == sin[a]) {
                swap(res.first, res.second);
            }
            int cand = fr + sin[a] + res.first;
            if (cand - fr > b2res) {
                b2res = cand - fr;
            }
            while(pq != qs.size() && qs[pq] <= cand) {
                ans[qs[pq]] = x.first - cand + qs[pq];
                pq++;
            }
//            int bb = -1;
//            forn(b,0,n) {
//                if(b == a) continue;
//                if (cost[b] + cost[a] > c) continue;
//                if(bb == -1 || sin[bb] < sin[b]) bb = b;
//            }
//            if (bb !=- 1) {
//                int cand = fr + sin[a] + sin[bb];
//                if (cand - fr > b2res) {
//                    b2 = mp(a,bb);
//                    b2res = cand - fr;
//                }
//                while(pq != qs.size() && qs[pq] <= cand) {
//                    ans[qs[pq]] = x.first - cand + qs[pq];
//                    pq++;
//                }
//            }
//            else {
//                int cand = fr + sin[a];
//                while(pq != qs.size() && qs[pq] <= cand) {
//                    ans[qs[pq]] = x.first - cand + qs[pq];
//                    pq++;
//                }
//                if (sin[a] > b2res) {
//                    b2 = mp(a,a);
//                    b2res = cand - fr;
//                }
//            }
            
            
            if (!big[a]) {
                for(auto u : pr[a]) {
                    int b = u.first;
                    int abv = u.second;
                    int cand = fr + sin[a] + sin[b] + abv;
                    if (cand - fr > b2res) {
                        b2 = mp(a,b);
                        b2res = cand - fr;
                    }
                    while(pq != qs.size() && qs[pq] <= cand) {
                        ans[qs[pq]] = x.first - cand + qs[pq];
                        pq++;
                    }
                    if (big[b]) {
                        if((cand - fr) > bestpval[b]) {
                            bestpval[b] = cand - fr;
                            bestpair[b] = a;
                        }
                    }
                }
            }
            else {
                int b = bestpair[a];
                bestpval[a] += x.first - last;
                int cand = bestpval[a] + fr;
                if (cand - fr > b2res) {
                    b2 = mp(a,b);
                    b2res = cand - fr;
                }
                while(pq != qs.size() && qs[pq] <= cand) {
                    ans[qs[pq]] = x.first - cand + qs[pq];
                    pq++;
                }
                
//                updateforotherbig()
                for(auto bc : biglist) {
                    if (bc == a) continue;
                    if (pr[a].find(bc) != pr[a].end()) {
                        int cand = sin[a] + sin[bc] + pr[a][bc];
                        if((cand - fr) > bestpval[bc]) {
                            bestpval[bc] = cand ;
                            bestpair[bc] = a;
                        }
                    }
                }
            }
            last = x.first;
        }
    }
    
    for(auto x : q) printf("%d\n", ans[x]);
}