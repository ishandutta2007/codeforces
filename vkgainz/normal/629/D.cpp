#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const ld PI = 4*atan((ld)1);
ll seg[200005];
int n;
void upd(int i,ll v) {
    seg[i+=n] = v;
    while(i>1) {
        i/=2;
        seg[i] = max(seg[2*i],seg[2*i+1]);
    }
}
ll query(int l,int r) {
    l+=n, r+=n;
    ll ret = 0;
    while(l<r) {
        if(l%2) ret = max(ret,seg[l++]);
        if(r%2) ret = max(ret,seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
int main() {
    cin >> n;
    vector<pair<ll, int>> vals(n);
    for(int i=0;i<n;i++) {
        int r,h; cin >> r >> h;
        vals[i] = {r*1LL*r*1LL*h, -i};
    }
    sort(vals.begin(),vals.end());
    ll mx = 0;
    for(int i=0;i<n;i++) {
        ll u = vals[i].f+query(0,-vals[i].s);
        upd(-vals[i].s,u);
        mx = max(mx,u);
    }
    double ans = mx*1.0*PI;
    cout << setprecision(24) << ans;
    
}