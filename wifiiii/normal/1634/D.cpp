#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        auto ask = [&](int i, int j, int k) {
            assert(i != j && j != k && i != k);
            cout << "? " << i << " " << j << " " << k << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        auto go = [&](vector<int> a) -> vector<int> {
            assert(a.size() == 4);
            // 0111 1
            vector<pair<int,int>> b;
            for(int s : {7, 11, 13, 14}) {
                vector<int> q;
                for(int i = 0; i < 4; ++i) {
                    if(s >> i & 1) {
                        q.push_back(a[i]);
                    }
                }
                b.push_back({ask(q[0], q[1], q[2]), s});
            }
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            int ms = b[0].second & b[1].second;
            vector<int> ret;
            for(int i = 0; i < 4; ++i) {
                if(ms >> i & 1) {
                    ret.push_back(a[i]);
                }
            }
            assert(ret.size() == 2);
            return ret;
        };
        vector<int> res(n);
        iota(res.begin(), res.end(), 1);
        while(res.size() >= 3) {
            if(res.size() == 3) {
                for(int i = 1; i <= n; ++i) {
                    if(i != res[0] && i != res[1] && i != res[2]) {
                        res.push_back(i);
                        break;
                    }
                }
            }
            vector<int> a;
            for(int i = 0; i < 4; ++i) {
                a.push_back(res.back());
                res.pop_back();
            }
            vector<int> b = go(a);
            res.push_back(b[0]);
            res.push_back(b[1]);
        }
        assert(res.size() == 2);
        cout << "! " << res[0] << ' ' << res[1] << endl;
    }
}