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
class streebasic {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            s = n;
        }
        if (tl == tr)
            t[v] = 0;
        else {
            int tm = (tl + tr) / 2;
            build (n, v*2, tl, tm);
            build (n, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  (
                 get (v*2, tl, tm, l, min(r,tm)) +
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  (t[v*2]+ t[v*2+1]);
        }
    }
};

class stree {
public:
    vll t;
    vi pp;
    int s;
    void build (int n, int v, int tl, int tr) {
        if(v==1) {
            t.resize(n * 4);
            pp = vi(n*4,0);
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
        t[v] += ll(pp[v])*(tr-tl+1);
        if(tl != tr) {
            pp[2*v] += pp[v];
            pp[2*v+1] += pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] += val;
            push(v,tl,tr);
            return;
        }
        if (l > r) {
            push(v, tl, tr);
            return;
        }
        else {
            push(v,tl,tr);
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), val);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        ll ret =  (get(v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = (t[v*2] + t[v*2+1]);
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
    read(n);
    readv(a,n);
    vi w(n);
    forn(i,0,n) {
        a[i]--;
        w[a[i]] = i;
    }
    streebasic st1;
    stree st;
    st.build(n, 1, 0, n-1);
    st1.build(n, 1, 0, n-1);
    ll ans = 0;
    set<int> got;
    int midwal = -1;
    ll getout = 0;
    int runleft= 0;
    int runright = 0;
    forn(i,0,n) {
        int cur = w[i];
        int toleft = st1.get(1, 0, n-1, 0, cur);
        ans += i-toleft;
        st1.update(1, 0, n-1, cur, 1);
        got.insert(cur);
        auto it = got.find(cur);
        if(i == 0) midwal = cur;
        else {
            if(i%2 == 1 && toleft < i-toleft) {
                auto itm = got.find(midwal);
                midwal = *(--itm);
            }
            else if(i%2 == 0 && toleft >= i-toleft) {
                auto itm = got.find(midwal);
                midwal = *(++itm);
            }
        }
//        if(i%2 == 0) {
//            auto itm = got.find(midwal);
//            if(toleft == i - toleft) {
//                if(i>0) {
//                    itm++;
//                    int ch = (*itm) - midwal - 1;
//                    runleft -= ch;
//                    runright += ch;
//                }
//            }
//        }
        if(toleft < i-toleft) {
            it++;
            int r = midwal - 1;
            if(i%2 == 1) {
                auto itm = got.find(midwal);
                itm ++;
                r = (*itm) - 1;
            }
            st.update(1, 0, n-1, cur+1, r, 1);
            ans -= st1.get(1, 0, n-1, cur+1, r);
            st.update(1, 0, n-1, cur, cur, -toleft);
        }
        else if(i-toleft < toleft) {
            it --;
            int l = midwal + 1;
            st.update(1, 0, n-1, l, cur-1, 1);
            ans -= st1.get(1, 0, n-1, l, cur-1);
            st.update(1, 0, n-1, cur, cur, -(i-toleft));
        }
        else st.update(1, 0, n-1, cur, cur, -toleft);
        printf("%lld ", ans + st.get(1,0,n-1,0,n-1));
        
        
    }
    
    
    
    
    
}