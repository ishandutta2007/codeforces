#include <bits/stdc++.h>
using namespace std;
 
 
int query(int y) {
    cout << y << "\n";
    int r; cin >> r;
    return r;
}
 
int kXOR(int x, int y, int k) {
    vector<int> dx(30), dy(30);
    int r = 0, s = 0;
    while(x > 0)
        dx[r++] = (x % k), x /= k;
    while(y > 0)
        dy[s++] = (y % k), y /= k;
    reverse(dx.begin(), dx.end());
    reverse(dy.begin(), dy.end());
    vector<int> ans(30);
    for(int i = 0; i < 30; i++) {
        ans[i] = (dy[i] + dx[i]) % k;
    }
    int ret = 0;
    for(int i = 0; i < 30; i++) {
        if(ans[i] == 0) continue;
        ret += ans[i] * pow(k, 29 - i);
    }
    return ret;
}
 
int XORpow(int i, int num, int k) {
    if(num == 0) return 0;
    int x = XORpow(i, num / 2, k);
    x = kXOR(x, x, k);
    if(num % 2) x = kXOR(x, i, k);
    return x;
}
 
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int rep = 1;
        int so_far = 0;
        vector<int> q;
        for(int i = 0; i < n; i++) {
            int curr_make = XORpow(i, rep, k);
            q.push_back(kXOR(curr_make, so_far, k));
            so_far = XORpow(so_far, k - 1, k);
            so_far = kXOR(so_far, q.back(), k);
            rep = rep * (k - 1);
            rep %= k;
        }
        for(auto &it : q) {
            query(it);
        }
    }
}