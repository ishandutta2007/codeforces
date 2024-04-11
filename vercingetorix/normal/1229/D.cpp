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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int n,k;
vvi a;
map<vi, int> pto;
vvi pmtable;
int bmt[200][200];
int init[200];
int cnt[200];

vi combine(vi & a, vi & b) {
    vi c;
    forn(i,0,k) c.pb(b[a[i]]);
    return c;
}

set<int> complete(set<int> x) {
    vi ord;
    for(auto y : x) ord.pb(y);
    for(int i = 0; i<ord.size(); i++) {
        if(ord.size() == a.size()) break;
        forn(j,0,i+1) {
//            vi t1 = combine(ord[i], ord[j]);
//            vi t2 = combine(ord[j], ord[i]);
            int t1 = pmtable[ord[i]][ord[j]];
            int t2 = pmtable[ord[j]][ord[i]];
            if(x.find(t1) == x.end()) {
                x.insert(t1);
                ord.pb(t1);
            }
            if(x.find(t2) == x.end()) {
                x.insert(t2);
                ord.pb(t2);
            }
        }
    }
    return x;
}

int rv[20][200500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    
    vi q;
    forn(i,0,k) q.pb(i);
    do {
        a.pb(q);
    } while(next_permutation(all(q)));
    int pnum = 0;
    forn(i,0,a.size()) pto[a[i]] = pnum++;
    pmtable = vvi(pnum, vi(pnum, 0));
    forn(i,0,pnum) forn(j,0,pnum) {
        pmtable[i][j] = pto[combine(a[i], a[j])];
    }
    set<set<int>> basis;
    set<int> def;
    map<set<int>, int> bnum;
    vector<set<int>> ord;
    int cnum = 0;
    forn(x,0,a.size()) {
        set<int> cur;
        cur.insert(x);
        cur = complete(cur);
        if(basis.find(cur) == basis.end()) {
            bnum[cur] = cnum++;
            basis.insert(cur);
            ord.pb(cur);
        }
        init[x] = bnum[cur];
    }
    for(int i = 0; i < cnum; i++) {
//        if(basis.size() == 156) break;
        forn(j,0,i+1) {
            set<int> cur = ord[i];
            for(auto x : ord[j]) cur.insert(x);
            cur = complete(cur);
            if(basis.find(cur) == basis.end()) {
                bnum[cur] = cnum++;
                basis.insert(cur);
                ord.pb(cur);
            }
            bmt[i][j] = bnum[cur];
            bmt[j][i] = bnum[cur];
//            if(basis.size() == 156) break;
        }
    }
//    def.insert(a[0]);
//    basis.insert(def);
//    forn(i,0,2) {
//        forn(j,i+1,k) {
//            forn(p,i+1,k) {
//                forn(q,i+1,k) {
//                    if(j!=p && j!=q && p!=q) {
//                        vi b = a[0];
//                        b[i]=j;
//                        b[j]=p;
//                        b[p]=q;
//                        b[q]=i;
//                        set<vi> cur;
//                        cur.insert(b);
//                        basis.insert(complete(cur));
//                        if(j<p && p < q) {
//                            cur.clear();
//                            b = a[0];
//                            b[i]=j;
//                            b[j]=p;
//                            b[p]=i;
//                            cur.insert(b);
//                            b= a[0];
//                            b[i] = p;
//                            b[p] = q;
//                            b[q]=i;
//                            cur.insert(b);
//                            basis.insert(complete(cur));
//                            b = a[0];
//                            b[i] = p;
//                            b[p] = i;
//                            basis.insert(complete(cur));
//                        }
//                    }
//                }
//            }
//        }
//    }
//    forn(i,0,k) {
//        forn(j,i+1,k) {
//            forn(p,i+1,k) {
//                forn(q,j+1,k) {
//                    if(p==j || q==j) continue;
//                    vi b = a[0];
//                    b[i]=j;
//                    b[j]=i;
//                    b[p]=q;
//                    b[q]=p;
//                    set<vi> cur;
//                    cur.insert(b);
//                    basis.insert(complete(cur));
//                    b = a[0];
//                    b[i]=j;
//                    b[j]=i;
//                    cur.insert(b);
//                    basis.insert(complete(cur));
//                }
//            }
//        }
//    }
//    forn(i,0,k) {
//        forn(j,i+1,k) {
//            vi lf;
//            forn(p,0,k) if(p!=i && p!=j) lf.pb(p);
//            vi b = a[0];
//            b[i]=j;
//            b[j]=i;
//            b[lf[0]]=lf[1];
//            b[lf[1]]=lf[2];
//            b[lf[2]]=lf[0];
//            set<vi> cur;
//            cur.insert(b);
//            basis.insert(complete(cur));
//        }
//    }
//    forn(i,0,k) {
//        forn(j,i+1,k) {
//            forn(p,i+1,k) {
//                if(p==j) continue;
//                vi b = a[0];
//                b[i]=j;
//                b[j]=p;
//                b[p]=i;
//                set<vi> cur;
//                cur.insert(b);
//                basis.insert(complete(cur));
//                if(j<p) {
//                    b = a[0];
//                    b[i]=j;
//                    b[j]=i;
//                    cur.insert(b);
//                    basis.insert(complete(cur));
//                }
//            }
//        }
//    }
//    forn(i,0,k) {
//        forn(j,i+1,k) {
//            vi b = a[0];
//            b[i]=j;
//            b[j]=i;
//            set<vi> cur;
//            cur.insert(b);
//            basis.insert(complete(cur));
//        }
//    }
////    vector<set<vi>> add;
////    add.pb(def);
////    while(!add.empty()) {
////        set<vi> cur = add.back();
////        add.pop_back();
////        forn(i,0,a.size()) if(cur.find(a[i]) == cur.end()) {
////            cur.insert(a[i]);
////            auto cand = complete(cur);
////            if(basis.find(cand) == basis.end()) {
////                basis.insert(cand);
////                add.pb(cand);
////            }
////            cur.erase(a[i]);
////        }
////    }
    for(auto x : bnum) cnt[x.second] = x.first.size();
//    cout<<basis.size();
    vi b;
    forn(i,0,n) {
        vi xxx(k);
        forn(j,0,k) scanf("%d", &xxx[j]);
        forn(j,0,k) xxx[j]--;
        b.pb(init[pto[xxx]]);
    }
    forn(i,0,n-1) rv[0][i] = bmt[b[i]][b[i+1]];
    rv[0][n-1] = b[n-1];
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back() * 2);
    forn(l,1,20) forn(i,0,n) {
        if(i+d2[l-1] < n) rv[l][i] = bmt[rv[l-1][i]][rv[l-1][i+d2[l-1]]];
        else rv[l][i] = rv[l-1][i];
    }
    ll ans = 0;
    forn(i,0,n) {
        int r = i;
        int cur = b[r];
        while (1) {
            int l = 0;
            for(int deg = 19; deg >= 0; deg --) {
                if(r + d2[deg] < n && bmt[cur][rv[deg][r]] == cur) {
                    r+=d2[deg];
                    l+=d2[deg];
                }
            }
            ans += ll(l+1)*cnt[cur];
            r++;
            if(r==n) break;
            cur = bmt[cur][b[r]];
        }
    }
    cout<<ans;
}