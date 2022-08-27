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

class stree {
public:
    vi t;
    vi k;
    vi b;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            k = vi(n*4,1);
            b = vi(n*4,0);
            s = n;
        }
        if (tl == tr)
            t[v] = 1;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
        }
    }
    
    void push(int v, int tl, int tr) {
        if(tl != tr) {
            b[2*v+1] = k[v]*b[2*v+1] + b[v];
            k[2*v+1] *= k[v];
            b[2*v] = k[v]*b[2*v] + b[v];
            k[2*v] *= k[v];
        }
        else {
            t[v] = t[v]*k[v] + b[v];
        }
        k[v] = 1;
        b[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int kn, int bn) {
        //        cout<<"UPD "<<tl<<' '<<tr<<' '<<l<<' '<<r<<' '<<val<<endl;
        if (l == tl && tr == r) {
            push(v,tl,tr);
            k[v] = kn;
            b[v] = bn;
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
            update (v*2, tl, tm, l, min(r,tm), kn, bn);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, kn, bn);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  (get(v*2, tl, tm, l, min(r,tm))+ get(v*2+1, tm+1, tr, max(l,tm+1), r));
        return ret;
    }
};

const int A = 100500;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    stree st;
    st.build(2*A+1, 1, 0, 2*A);
    readv(a,n);
    forn(i,0,q) {
        int x;
        char c;
        scanf("\n%c %d", &c, &x);
//        cout<<c<<endl;
        if(c == '>') {
            if(x >= 0) {
                st.update(1, 0, 2*A, A+x+1, 2*A, 0, -1);
                st.update(1, 0, 2*A, 0, A-x-1, 0, 1);
            }
            else {
                st.update(1, 0, 2*A, A+x+1, A-x-1, -1, 0);
                st.update(1, 0, 2*A, 0, A+x, 0, 1);
                st.update(1, 0, 2*A, A-x, 2*A, 0, -1);
            }
        }
        else {
            if(x <= 0) {
                st.update(1, 0, 2*A, A-x+1, 2*A, 0, 1);
                st.update(1, 0, 2*A, 0, A+x-1, 0, -1);
            }
            else {
                st.update(1, 0, 2*A, A-x+1, A+x-1, -1, 0);
                st.update(1, 0, 2*A, 0, A-x, 0, -1);
                st.update(1, 0, 2*A, A+x, 2*A, 0, 1);
            }
        }
    }
    forn(i,0,n) {
        printf("%d ", a[i] * st.get(1, 0, 2*A, A+a[i], A+a[i]));
    }
    
    
}