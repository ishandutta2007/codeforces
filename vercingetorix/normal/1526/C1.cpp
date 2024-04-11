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
class stree {
public:
    vll t;
    vll pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vll(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v] += pp[v];
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        //            t[v] = max(t[v],val);
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v, tl, tr);
        //        }
        if (l>r) return INF;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  min(get(v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = min(t[v*2], t[v*2+1]);
        return ret;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    readv(a,n);
    stree st;
    st.build(n, 1, 0, n-1);
    int ans = 0;
    vpi e;
    forn(i,0,n) {
        if(a[i]>=0) {
            ans++;
            st.update(1, 0, n-1, i, n-1, a[i]);
        }
        else {
            e.pb(mp(a[i], i));
        }
    }
    srtrev(e);
    for(auto x:e) {
        int ind = x.second;
        if(st.get(1, 0, n-1, ind, n-1) + a[ind] >= 0) {
            ans++;
            st.update(1, 0, n-1, ind, n-1, a[ind]);
        }
    }
    cout<<ans;
    
    
}