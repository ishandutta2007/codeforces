#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;


struct BIT{
    ll a[N];
    void add(int x, ll v) {
        while (x < N) {
            a[x] += v;
            x += x & -x;
        }
    }
    ll get(int x) {
        ll ans = 0;
        while (x) {
            ans += a[x];
            x -= x & -x;
        }
        return ans;
    }
    int findKth(int k) {
        int ans = 0;
        for(int i = 20; i >= 0; i--) {
            int pos = ans + (1 << i);
            if (pos >= N) continue;
            if (k > a[pos]) ans = pos, k -= a[pos];
        }
        return ans + 1;
    }
}mBit, psum;

int n;
int a[N], pos[N];
ll ans[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;


    long long inv = 0;
    for(int i = 1; i <= n; i++) {
        mBit.add(pos[i], 1);
        psum.add(pos[i], pos[i]);

        inv += i - mBit.get(pos[i]);


        int half = mBit.findKth((i + 1) / 2);

        long long sumR = psum.get(N - 1) - psum.get(half);
        long long sumL = psum.get(half);
        if (i % 2) sumL -= half;

        long long dist = sumR - sumL;

        long long need = (i + 1) / 2;
        long long odd = i % 2 ? 0 : 1; 
        dist -= (odd + need - 1) * need;
        //cout << half << " " << inv << " " << dist << endl;

        ans[i] = inv + dist;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";

}