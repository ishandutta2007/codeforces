#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 2e5+5;
long long sum[4*MX], mn[4*MX], lazy[4*MX], mx[4*MX];
int sz = 1;
void build(vector<int> &nums, int x=0, int lx=0, int rx=sz) {
    if(rx-lx==1) {
        if(lx<nums.size()) {
            sum[x] = nums[lx], mn[x] = nums[lx], mx[x] = nums[lx];
        }
        else {
            sum[x] = 0LL, mn[x] = 0LL, mx[x] = 0LL;
        }
        return;
    }
    int m = (lx+rx)/2;
    build(nums, 2*x+1, lx, m), build(nums, 2*x+2, m, rx);
    sum[x] = sum[2*x+1]+sum[2*x+2];
    mn[x] = min(mn[2*x+1], mn[2*x+2]);
    mx[x] = max(mx[2*x+1], mx[2*x+2]);
}
void prop(int x, int lx, int rx) {
    if(lazy[x]==0)
        return;
    sum[x] = lazy[x]*1LL*(rx-lx);
    mn[x] = lazy[x];
    mx[x] = lazy[x];
    if(rx-lx!=1) {
        lazy[2*x+1] = lazy[x];
        lazy[2*x+2] = lazy[x];
    }
    lazy[x] = 0LL;
    return;
}
int find(int y, int x=0, int lx=0, int rx=sz) {
    //returns the first index a[x]<y
    prop(x, lx, rx);
    if(mx[x]<y)
        return lx;
    if(rx-lx==1 || mn[x]>=y) 
        return 1000000000;
    int m = (lx+rx)/2;
    prop(2*x+1, lx, m), prop(2*x+2, m, rx);
    if(mn[2*x+1]<y) return find(y, 2*x+1, lx, m);
    else
        return find(y, 2*x+2, m, rx);

}
void upd(int l, int r,int y, int x=0, int lx=0, int rx=sz) {
    prop(x, lx, rx);
    if(lx>=r || rx<=l) return;
    if(lx>=l && rx<=r) {
        sum[x] = y*1LL*(rx-lx);
        mn[x] = y;
        mx[x] = y;
        if(rx-lx!=1) {
            lazy[2*x+1] = y;
            lazy[2*x+2] = y;
        }
        return;
    }
    int m = (lx+rx)/2;
    upd(l, r, y, 2*x+1, lx, m), upd(l, r, y, 2*x+2, m, rx);
    sum[x] = sum[2*x+1]+sum[2*x+2];
    mn[x] = min(mn[2*x+1], mn[2*x+2]);
    mx[x]= max(mx[2*x+1], mx[2*x+2]);
}
long long take;

int query(int st, int x=0, int lx=0, int rx=sz) {
    prop(x, lx, rx);
    if(rx<=st)
        return 0;
    if(lx>=st) {
        if(mn[x]>take) return 0;
        if(sum[x]<=take) {
            take-=sum[x];
            return rx-lx;
        }
        int m = (lx+rx)/2;
        return query(st, 2*x+1, lx, m)+query(st, 2*x+2, m, rx);
    }
    int m = (lx+rx)/2;
    return query(st, 2*x+1, lx, m)+query(st, 2*x+2, m, rx);
}
int main() {
    int n, q; cin >> n >> q;
    while(sz<n) sz*=2;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(a);
    while(q--) {
        int t, x, y; cin >> t >> x >> y;
        if(t==1) {
            int st = find(y);
            if(st<x)
                upd(st, x, y);
        }
        else {
            --x;
            take = y;
            cout << query(x)-(sz-n) << "\n";
        }
    }
}