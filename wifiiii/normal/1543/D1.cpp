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
        auto Xor = [&](int x, int y) {
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
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            int g = Xor(cur, i);
            if(guess(g)) break;
            cur = Xor(cur, g);
        }
    }
}