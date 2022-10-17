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
        vector<int> deg(n);
        for(int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            --p;
            deg[p]++;
        }
        vector<int> a;
        for(int i : deg) {
            if(i > 0) a.push_back(i);
        }
        a.push_back(1);
        sort(a.begin(), a.end(), greater<int>());
        int lo = a.size(), hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = 0;
            for(int i = 0; i < a.size(); ++i) {
                int res = max(0, a[i] - (mid - i));
                cnt += res;
                if(cnt > mid - a.size()) {
                    break;
                }
            }
            if(cnt > mid - a.size()) lo = mid + 1;
            else hi = mid;
        }
        cout << lo << '\n';
    }
}