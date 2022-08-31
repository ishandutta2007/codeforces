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

class stree {
public:
    vll t;
    vll pp;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            s = a.size();
            t.resize(s * 4);
            pp = vll(s*4,0);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void push(int v, int tl, int tr) {
        if(pp[v] == 0) return;
        t[v] = pp[v] * (tr-tl+1);
        if(tl != tr) {
            pp[2*v] = pp[v];
            pp[2*v+1] = pp[v];
        }
        pp[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int val) {
        if (l == tl && tr == r) {
            pp[v] = val;
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
            t[v] = (t[v*2] + t[v*2+1]);
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        //        if(tl!=tr) {
        push(v, tl, tr);
        //        }
        if (l>r) return 0;
        if (tl ==l && r== tr)
            return t[v];
        int tm = (tl + tr) / 2;
        int ret =  (get(v*2, tl, tm, l, min(r,tm))+ get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = (t[v*2]+ t[v*2+1]);
        return ret;
    }
    
    int getr(int v, int tl, int tr) {
        push(v, tl, tr);
        if (t[v] <= 0) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int vr = getr(v*2+1,tm+1,tr);
        if (vr >= 0) return vr;
        return getr(v*2,tl,tm);
    }
    
    pll go(int v, int tl, int tr, int l, ll sum) {
        push(v, tl, tr);
        if(tl == l) {
            if(t[v] <= sum) return mp(tr, t[v]);
        }
        if(tl == tr) {
            if(t[v] <= sum) return mp(tr, t[v]);
            else return mp(tl-1, 0);
        }
        int tm = (tl + tr)/2;
        ll add  =0;
        if(l <= tm) {
            pll ret = go(v*2, tl, tm, l, sum);
            if(ret.first < tm) return ret;
            sum -= ret.second;
            add += ret.second;
        }
        pll ret2 = go(v*2+1, tm+1, tr, max(l, tm+1), sum);
        ret2.second += add;
        return ret2;
    }
    
//    void go(int v, int tl, int tr) {
//        push(v, tl, tr);
//        if (tl==tr) {
//            cout<<t[v]<<' ';
//            return;
//        }
//        int tm = (tl + tr) / 2;
//        go(v*2,tl,tm);
//        go(v*2+1,tm+1,tr);
//    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,qnum;
    scanf("%d %d", &n, &qnum);
    readv(a,n);
    stree st;
    st.build(a, 1, 0, n-1);
    set<pair<int, pi>> q;
    forn(i,0,n) q.insert(mp(-a[i], mp(i,i)));
    forn(i,0,qnum) {
        int tp, x, y;
        scanf("%d %d %d", &tp, &x, &y);
        x--;
        if(tp == 1) {
            auto it = q.lower_bound(mp(-y+1, mp(0, 0)));
            vector<pair<int, pi>> del;
            while(it != q.end() && it->second.first <= x) {
                del.pb(*it);
                it++;
            }
            if(del.empty()) continue;
            int l = del[0].second.first;
            if(del.back().second.second > x) {
                q.insert(mp(del.back().first, mp(x+1, del.back().second.second)));
            }
            for(auto dd : del) q.erase(dd);
            q.insert(mp(-y, mp(l,x)));
            st.update(1, 0, n-1, l, x, y);
        }
        else if(tp == 2) {
            int ans = 0;
            while(1) {
                auto it = q.lower_bound(mp(-y, mp(0, 0)));
                if(it == q.end()) break;
                int l = max(it->second.first, x);
                pll ret = st.go(1, 0, n-1, l, y);
                ans += ret.first - l + 1;
                y -= ret.second;
                if(ret.first == n-1) break;
            }
            printf("%d\n", ans);
        }
    }
    
}