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

class stree {
public:
    int s;
    vll t;
    vll lazy;
    void build (int n) {
        s = n;
        t = vll(4*n,0);
        lazy = vll(4*n,0);
    }
    
    void push(int v, int tl, int tr) {
        if (lazy[v] == 0) return;
        t[v] += lazy[v]*(tr-tl+1);
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2 + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, ll add) {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v, tl, tr);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = (t[v*2] + t[v*2 + 1]);
        }
    }
    
    ll gsum (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (l == tl && tr == r) {
            push(v, tl, tr);
            return t[v];
        }
        else {
            int tm = (tl + tr) / 2;
            ll ret = gsum(v*2, tl, tm, l, min(r,tm)) +
                         gsum(v*2+1, tm+1, tr, max(l,tm+1), r);
            t[v] = t[v*2] + t[v*2 + 1];
            return ret;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int curl = 0;
    stree st;
    const int A = 200100;
    st.build(A);
    int n;
    scanf("%d", &n);
    forn(i,0,n) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int x,a;
            scanf("%d %d", &a, &x);
            a--;
            st.update(1, 0, A-1, 0, a, x);
        }
        else if(t==2) {
            curl++;
            ll was  = st.gsum(1, 0, A-1, curl, curl);
            int x;
            scanf("%d", &x);
            st.update(1, 0, A-1, curl, curl, ll(x)-was);
        }
        else if(t==3) {
            curl--;
        }
//        cout<<"CURRENT:\n";
//        forn(j,0,curl+1) cout<< st.gsum(1, 0, A-1, j, j)<<' ';
//        cout<<"\n\n";
        ld sum = st.gsum(1, 0, A-1, 0, curl);
        printf("%.10lf\n", double(sum/(curl+1)));
    }
    
}