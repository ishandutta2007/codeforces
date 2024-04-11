
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
const ll INF = 1e18;
const int N = 100002;

const int d2 = 16;
ll t[4*N][d2];
ll pp[4*N][d2];
//class stree {
//public:
//    void build (int ind, int n) {
//        forn(i,0,4*n) t[ind][i] = INF;
//    }
//
//    ll get (int v, int tl, int tr, int l, int r, int ind) {
//        if (l > r)
//            return INF;
//        if (l == tl && r == tr)
//            return t[ind][v];
//        int tm = (tl + tr) / 2;
//        return  min(
//                 get (v*2, tl, tm, l, min(r,tm), ind),
//                 get (v*2+1, tm+1, tr, max(l,tm+1), r, ind)
//                 );
//    }
//
//    void update (int v, int tl, int tr, int pos, ll new_val, int ind) {
//        if (tl == tr)
//            t[ind][v] = new_val;
//        else {
//            int tm = (tl + tr) / 2;
//            if (pos <= tm)
//                update (v*2, tl, tm, pos, new_val, ind);
//            else
//                update (v*2+1, tm+1, tr, pos, new_val, ind);
//            t[ind][v] =  min(t[ind][v*2], t[ind][v*2+1]);
//        }
//    }
//
//    void addall (int v, int tl, int tr, int pos, ll new_val) {
//        if (tl == tr) {
//            forn(ind,0,20) t[ind][v] += new_val;
//        }
//        else {
//            int tm = (tl + tr) / 2;
//            if (pos <= tm)
//                addall (v*2, tl, tm, pos, new_val);
//            else
//                addall (v*2+1, tm+1, tr, pos, new_val);
//            forn(ind,0,20) t[ind][v] =  min(t[ind][v*2], t[ind][v*2+1]);
//        }
//    }
//};

class stree {
public:
    void build (int ind, int n) {
        forn(i,0,4*n) {
            t[i][ind] = INF;
        }
        
    }
    
    void push(int v, int tl, int tr, int ind) {
        if(pp[v][ind] == 0) return;
        t[v][ind] += pp[v][ind];
        if(tl != tr) {
            pp[2*v][ind] += pp[v][ind];
            pp[2*v+1][ind] += pp[v][ind];
        }
        pp[v][ind] = 0;
    }
    
    void pushall(int v, int tl, int tr) {
        forn(ind,0,d2) push(v,tl,tr,ind);
    }
    
    void addall (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            forn(ind,0,d2) pp[v][ind] += val;
            pushall(v,tl,tr);
            return;
        }
        if (l > r) {
            pushall(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            pushall(v,tl,tr);
            int tm = (tl + tr) / 2;
            addall (v*2, tl, tm, l, min(r,tm), val);
            addall (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            forn(ind,0,d2) t[v][ind] = min(t[v*2][ind], t[v*2+1][ind]);
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, ll val, int ind) {
        if (l == tl && tr == r) {
            //            forn(ind,0,d2) pp[ind][v] += val;
            t[v][ind] = val;
            pp[v][ind] = 0;
            return;
        }
        if (l > r) {
            push(v, tl, tr,ind);
            return;
        }
        else {
            push(v,tl,tr,ind);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val, ind);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val, ind);
            t[v][ind] = min(t[v*2][ind], t[v*2+1][ind]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r, int ind) {
        push(v, tl, tr, ind);
        if (l>r) return INF;
        if (tl ==l && r== tr)
            return t[v][ind];
        int tm = (tl + tr) / 2;
        ll ret =  min(get(v*2, tl, tm, l, min(r,tm), ind), get(v*2+1, tm+1, tr, max(l,tm+1), r, ind));
        t[v][ind] = min(t[v*2][ind], t[v*2+1][ind]);
        return ret;
    }
};

//stree st[d2];
stree st;
ll ans[d2+1][N];
vi mindiv(N+1, 0);
vi maxdiv(N+1, 0);
vi sqf(N+1,0);
vi pn(N+1,0);
vector<ll> pr;
vi isp(N+1, 0);
const int M = 100002;
vi divs[M];
vi pdivs[M];
int phi[M];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    phi[1] = 1;
    forn(i,2,M) {
        int m = i / mindiv[i];
        sqf[i] = sqf[m];
        pn[i] = pn[m];
        divs[i] = divs[m];
        maxdiv[i] = maxdiv[m];
        if(m==1) maxdiv[i] = i;
        pdivs[i] = pdivs[m];
        if(m%mindiv[i] == 0) {
            phi[i] = phi[m] * mindiv[i];
            sqf[i] *= mindiv[i];
            pn[i]++;
            for(auto x : divs[m]) divs[i].pb(x*mindiv[i]);
            divs[i].pb(mindiv[i]);
        }
        else {
            phi[i] = phi[m] * (mindiv[i] - 1);
            pdivs[i].pb(mindiv[i]);
        }
    }
    forn(l,0,d2) {
        forn(i,0,N) ans[l][i] = INF;
        st.build(l, N);
    }
    //    forn(i,0,4*N) t[0][i] = 0;
    st.update(1, 0, N-1, 0, 0, 0, 0);
    //    st[0].update(1, 0, N-1, 0, 0);
    forn(r,1,N) {
        for(int k = 1; k*k <= r; k++) {
            if(r%k == 0) {
                st.addall(1, 0, N-1, 0, k-1, phi[r/k]);
                if(k*k < r) {
                    st.addall(1, 0, N-1, 0, r/k-1, phi[k]);
                }
            }
            
        }
        forn(k,1,d2+1) {
            ans[k][r] = st.get(1, 0, N-1, 0, r-1, k-1);
            if(k<d2) st.update(1, 0, N-1, r, r, ans[k][r], k);
        }
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d", &n, &k);
        if(k>=d2+1) printf("%d\n", n);
        else printf("%lld\n", ans[k][n]);
    }
    
    
}