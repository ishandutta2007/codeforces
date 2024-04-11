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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

const int MAXN = 400009;
int n;
//ll t[4*MAXN];
//void build (vi & a, int v, int tl, int tr) {
//    if (tl == tr)
//        t[v] = a[tl];
//    else {
//        int tm = (tl + tr) / 2;
//        build (a, v*2, tl, tm);
//        build (a, v*2+1, tm+1, tr);
//    }
//}
//
//void update (int v, int tl, int tr, int l, int r, ll add) {
//    if (l > r)
//        return;
//    if (l == tl && tr == r)
//        t[v] += add;
//    else {
//        int tm = (tl + tr) / 2;
//        update (v*2, tl, tm, l, min(r,tm), add);
//        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
//    }
//}
//
//
//
//ll get (int v, int tl, int tr, int pos) {
//    if (tl == tr)
//        return t[v];
//    int tm = (tl + tr) / 2;
//    if (pos <= tm)
//        return t[v] + get (v*2, tl, tm, pos);
//    else
//        return t[v] + get (v*2+1, tm+1, tr, pos);
//}


set<int> peaks;
//vi isp, isb;
int isp[300000];
int isb[300000];
//vi pval;
int pval[300000];
set<int> br;
//vi eq;
int eq[300000];
multiset<int> w;

bool isc(ll a, ll b, ll c) {
    if(a>c) {
        if(b>=a || b<=c) return false;
        else return true;
    }
    else {
        if(b>=c || b<=a) return false;
        else return true;
    }
//    if(a>b && b>c) return true;
//    if(a<b && b<c) return true;
//    return false;
}

void upd_peak(int pos) {
    int wd = 1;
    auto it = br.lower_bound(pos);
    if(pos > 0) {
        if(!eq[pos-1]) {
            it--;
            wd += pos-*it;
        }
    }
    if(pos<n-1) {
        if(!eq[pos]) {
            while (it != br.end() && (*it) <= pos) it++;
            wd += *it-pos;
        }
    }
    pval[pos] = wd;
}

void reset_peak(int pos) {
    w.erase(w.find(pval[pos]));
    upd_peak(pos);
    w.insert(pval[pos]);
}
ll b[300000];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    w.insert(1);
    
    
    scanf("%d", &n);
    
//    isp = vi(n,1);
//    isb = vi(n,1);
//    b = vll(n,0);
    forn(i,0,n) {
        isp[i] = 1;
        isb[i] = 1;
        b[i] = 0;
        pval[i] = 0;
        eq[i] = 0;
    }
//    eq=vi(n,0);
    vi a(n);
    
    
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n-1) b[i] = a[i+1] - a[i];
    forn(i,0,n-1) if(a[i] < a[i+1]) isp[i] = 0;
    forn(i,1,n) if(a[i] < a[i-1]) isp[i] = 0;
    forn(i,0,n) if(isp[i]) peaks.insert(i);
    forn(i,1,n-1) {
        if(a[i-1] < a[i] && a[i] < a[i+1]) isb[i] = 0;
        if(a[i-1] > a[i] && a[i] > a[i+1]) isb[i] = 0;
    }
    forn(i,0,n-1) if(a[i] == a[i+1]) eq[i] = 1;
    forn(i,0,n) if(isb[i]) br.insert(i);
//    pval = vi(n,0);
//    build(a, 1, 0, n-1);
    forn(i,0,n) upd_peak(i);
    forn(i,0,n) if(isp[i]) w.insert(pval[i]);
    
    int m;
    scanf("%d", &m);
    forn(i,0,m) {
        int l,r,dd;
        scanf("%d %d %d", &l, &r, &dd);
        ll d = dd;
        l--;
        r--;
//        update(1, 0, n-1, l, r, d);
        vi peak_del;
        vi peak_ins;
        vi brflip;
        bool chl = false;
        bool chr = false;
        if(1) {
//            ll al  = get(1,0,n-1,l);
//            ll al1 = 0; if(l<n-1) al1 = get(1,0,n-1,l+1);
//            ll ar  = get(1,0,n-1,r);
//            ll arm1= 0; if(r>0) arm1 = get(1,0,n-1,r-1);
            ll al = 0;
            ll al1 =0; if(l<n-1) al1 = b[l];
            ll ar = 0;
            ll arm1= 0; if(r>0) arm1 = -b[r-1];
            bool pinslr = true;
            if(isp[l]) pinslr = false;
            if(l>0) {
                //ll alm1 = get(1,0,n-1,l-1);
                ll alm1 = -b[l-1];
                if(alm1 == al) eq[l-1] = 0;
                if(al + d < alm1) pinslr = false;
                else {
                    chl = true;
                    if(alm1 == al+d) eq[l-1]=1;
                    else if(isp[l-1]) peak_del.pb(l-1);
                }
                if(l<r) {
                    if(al >= al1 && al < alm1 && al + d >= alm1) {
                        peak_ins.pb(l);
                    }
                    if(isc(alm1,al,al1) ^ isc(alm1,al+d,al1+d)) brflip.pb(l);
                }
                else {
                    if(r<n-1) {
                        //ll ar1 = get(1,0,n-1,r+1);
                        ll ar1 = b[r];
                        if(isc(alm1,al,ar1) ^ isc(alm1,al+d,ar1)) brflip.pb(l);
                    }
                }
                if(l>1) {
                    //ll alm2 = get(1,0,n-1,l-2);
                    ll alm2 =alm1-b[l-2];
                    if(isc(alm2,alm1,al) ^ isc(alm2,alm1,al+d)) brflip.pb(l-1);
                }
            }
            if(r<n-1) {
                //ll ar1 = get(1,0,n-1,r+1);
                ll ar1 = b[r];
                if(ar1 == ar) eq[r] = 0;
                if(ar + d < ar1) pinslr = false;
                else {
                    chr = true;
                    if(ar1 == ar+d) eq[r]=1;
                    else if(isp[r+1]) peak_del.pb(r+1);
                }
                if(l<r) {
                    if(ar >= arm1 && ar < ar1 && ar + d >= ar1) {
                        peak_ins.pb(r);
                    }
                    if(isc(arm1,ar,ar1) ^ isc(arm1+d,ar+d,ar1)) brflip.pb(r);
                }
                else {
                    
                }
                if(r<n-2) {
                    //ll ar2 = get(1,0,n-1,r+2);
                    ll ar2 = ar1+b[r+1];
                    if(isc(ar,ar1,ar2) ^ isc(ar+d,ar1,ar2)) brflip.pb(r+1);
                }
            }
            if(l==r && pinslr) peak_ins.pb(l);
        }
        for(auto j : brflip) {
            if(isb[j]) br.erase(j);
            else br.insert(j);
            isb[j] = 1-isb[j];
        }
        
        for(auto pos : peak_del) {
            isp[pos] = 0;
            peaks.erase(pos);
            w.erase(w.find(pval[pos]));
        }
        for(auto pos : peak_ins) {
            isp[pos] =1;
            upd_peak(pos);
            peaks.insert(pos);
            w.insert(pval[pos]);
        }
//        update(1, 0, n-1, l, r, d);
        if(l>0) b[l-1]+=d;
        b[r]-=d;
        if(chl) {
            auto it = peaks.lower_bound(l);
            if(it != peaks.end()) reset_peak(*it);
            if(it!=peaks.begin()) reset_peak(*(--it));
        }
        if(chr) {
            auto it = peaks.lower_bound(r+1);
            if(it != peaks.end()) reset_peak(*it);
            if(it!=peaks.begin()) reset_peak(*(--it));
        }
        printf("%d\n", *(--w.end()));
    }
}