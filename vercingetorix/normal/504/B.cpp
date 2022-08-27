#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <cassert>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN = 200009;
int n, t[4*MAXN];
void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
    }
}

void update (int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), add);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}

int get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get (v*2, tl, tm, pos);
    else
        return t[v] + get (v*2+1, tm+1, tr, pos);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d", &n);
    vi a(n);
    vi b(n);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    vi c(n,0);
    vi an(n);
    vi bn(n);
    build(c.data(), 1, 0, n-1);
    for(int i = n-1; i>=0; i--) {
        an[i] = get(1,0,n-1,a[i]);
        update(1,0,n-1,a[i],n-1,1);
      //  cout<<an[i]<<" ";
    }
//    cout<<endl;
    c = vi(n,0);
    forn(i,0,4*MAXN) t[i]=0;
    build(c.data(), 1, 0, n-1);
    for(int i = n-1; i>=0; i--) {
        bn[i] = get(1,0,n-1,b[i]);
        update(1,0,n-1,b[i],n-1,1);
    //    cout<<bn[i]<<" ";
    }
 //       cout<<endl;
    // cout<<ans;
    vi sum(n,0);
    int carry = 0;
    for(int i = n-1; i>=0; i--) {
        sum[i] = an[i]+bn[i] + carry;
        carry = 0;
        if(sum[i]>n-1-i) {
            carry = 1;
            sum[i]-=(n-i);
            assert(sum[i]<n-i);
        }
    }
    
    forn(i,0,n) c[i]=i;
    forn(i,0,4*MAXN) t[i]=0;
    build(c.data(), 1, 0, n-1);
    forn(i,0,n) {
        int need = sum[i];
        int l = 0;
        int r = n-1;
        while(r-l>0) {
            int m = (l+r)/2;
            if(get(1,0,n-1,m) >= need) {
                r=m;
            }
            else l = m+1;
        }
        printf("%d ", l);
        update(1,0,n-1,l,n-1,-1);
    }
}