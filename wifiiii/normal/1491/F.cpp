#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        auto ask = [&](vector<int> l, vector<int> r) {
            cout << "? " << l.size() << " " << r.size() << endl;
            for(int i : l) cout << i << " "; cout << endl;
            for(int i : r) cout << i << " "; cout << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        int n;
        cin >> n;
        vector<int> l{1};
        int k = -1;
        for(int i = 2; i <= n; ++i) {
            int tmp = ask(l, vector<int>{i});
            if(tmp) {
                k = i;
                break;
            }
            l.push_back(i);
        }
        assert(k != -1);
        vector<int> ans;
        for(int i = k + 1; i <= n; ++i) {
            if(!ask(vector<int>{i}, vector<int>{k})) {
                ans.push_back(i);
            }
        }
        int lo = 1, hi = k - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            vector<int> a;
            for(int i = 1; i <= mid; ++i) {
                a.push_back(i);
            }
            if(ask(a, vector<int>{k})) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        for(int i = 1; i < k; ++i) {
            if(i != lo) ans.push_back(i);
        }
        cout << "! " << ans.size() << " ";
        for(int i : ans) cout << i << " "; cout << endl;
    }
}