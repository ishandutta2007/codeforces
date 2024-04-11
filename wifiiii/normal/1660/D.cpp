#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> sum(n + 1), f(n + 1);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (abs(a[i]) == 2);
        for(int i = 0; i < n; ++i) f[i + 1] = f[i] ^ (a[i] < 0);
        vector<int> nxt(n);
        int pos = n;
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] < 0) pos = i;
            nxt[i] = pos;
        }
        int mx = 0, l = 0, r = -1, pre = -1;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 0) {
                pre = i;
                continue;
            }
            int cnt = sum[i + 1] - sum[pre + 1];
            int sgn = f[i + 1] ^ f[pre + 1];
            if(sgn == 0) {
                if(cnt > mx) {
                    mx = cnt;
                    l = pre + 1;
                    r = i;
                }
            } else {
                if(nxt[pre + 1] < i) {
                    cnt = sum[i + 1] - sum[nxt[pre + 1] + 1];
                    if(cnt > mx) {
                        mx = cnt;
                        l = nxt[pre + 1] + 1;
                        r = i;
                    }
                }
            }
        }
        cout << l << ' ' << (n - 1) - r << '\n';
    }
}