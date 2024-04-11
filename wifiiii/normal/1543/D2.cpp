#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        auto guess = [&](int x) {
            cout << x << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        auto add = [&](int x, int y) {
            vector<int> a, b;
            while(x) {
                a.push_back(x % k);
                x /= k;
            }
            while(y) {
                b.push_back(y % k);
                y /= k;
            }
            if(a.empty()) a.push_back(0);
            if(b.empty()) b.push_back(0);
            if(a.size() > b.size()) swap(a, b);
            for(int i = 0; i < a.size(); ++i) {
                b[i] = (b[i] + a[i]) % k;
            }
            int ret = 0;
            for(int i = b.size() - 1; i >= 0; --i) {
                ret = ret * k + b[i];
            }
            return ret;
        };
        auto del = [&](int x, int y) {
            vector<int> a, b;
            while(x) {
                a.push_back(x % k);
                x /= k;
            }
            while(y) {
                b.push_back(y % k);
                y /= k;
            }
            if(a.empty()) a.push_back(0);
            if(b.empty()) b.push_back(0);
            int ret = 0;
            for(int i = max(b.size(), a.size()) - 1; i >= 0; --i) {
                int p = k;
                if(i < a.size()) p += a[i];
                if(i < b.size()) p -= b[i];
                ret = ret * k + p % k;
            }
            return ret;
        };
        int cur = 0, f = 0;
        for(int i = 0; i < n; ++i) {
            int g = 0;
            if(f) {
                g = del(cur, i);
            } else {
                g = add(cur, i);
            }
            if(guess(g)) break;
            cur = del(g, cur);
            f ^= 1;
        }
    }
}