#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct BIT {
    vector<T> a;
    int n;
    BIT() {}
    BIT(int _n) {n=_n+1;a.resize(n+1);}
    void init(int _n) {n=_n+1;a.resize(n+1);}
    void add(int x,T v){++x;for(;x<=n;x+=x&-x)a[x]+=v;}
    T sum(int x) {if(x<0)return 0;++x;T ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll sum = 0, ans = 0;
    BIT<int> bit(300005);
    BIT<ll> bit2(300005);
    int cnt = 0;
    for(int x : a) {
        // other % x = other - other / x * x
        // other / x : most 3e5 / x values
        bit.add(x, 1); sum += x; ++cnt;
        ans += sum; // include x itself
        for(int i = 0; x * i <= 300000; ++i) {
            int l = x * i, r = l + x - 1;
            r = min(r, 300000);
            ans -= 1ll * i * x * (bit.sum(r) - bit.sum(l-1));
        }
        // x % other = x - x / other * other
        // precalculate other -> x
        ans += 1ll * x * (cnt - 1); // exclude x
        ans -= bit2.sum(x);
        for(int i = 0; x * i <= 300000; ++i) {
            int l = x * i, r = l + x - 1;
            r = min(r, 300000);
            // [l, r] += i * x
            bit2.add(l, i * x);
            bit2.add(r + 1, - i * x);
        }
        cout << ans << " ";
    }
}