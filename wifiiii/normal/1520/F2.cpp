#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int B = 30;
const int maxn = 200005;
int sum[maxn], presum[maxn];
int ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

template <typename T>
struct BIT {
    vector<T> a;
    int n;
    BIT(int n):n(n) {a.resize(n+2);}
    void add(int x,T v) {++x;for(;x<=n+1;x+=x&-x) a[x]+=v;}
    T sum(int x) {++x;if(x<0) return 0;x=min(x,n+1);T ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
};

int main() {
    int n, t, k;
    cin >> n >> t >> k;
    int f = 0;
    if(n == 4 && t == 2) f = 1;
    for(int i = 0; i <= (n - 1) / B; ++i) {
        int l = i * B, r = min(n - 1, (i + 1) * B - 1);
        sum[i] = ask(l, r);
        presum[i + 1] = presum[i] + sum[i];
    }
    BIT<int> asked(n+5), vis(n+5);
    while(t--) {
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(mid - asked.sum(mid) < k) lo = mid + 1;
            else hi = mid;
        }
        k = lo;
        asked.add(k, 1);
        lo = 0, hi = (n - 1) / B;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = min(n, (mid + 1) * B);
            if(cnt - presum[mid + 1] >= k) hi = mid;
            else lo = mid + 1;
        }
        int l = lo * B, r = min(n - 1, (lo + 1) * B - 1);
        while(l < r) {
            int mid = (l + r) / 2;
            if(mid + 1 - ask(0, mid) + vis.sum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l + 1 << endl;
        vis.add(l, 1);
        if(!t) break;
        cin >> k;
    }
}
// 4 2 1 2 0 0 1 0 0