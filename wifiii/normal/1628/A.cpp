#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int cnt[N], cnt2[N];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i : a) cnt[i] += 1;
        int mex = 0;
        while(cnt[mex]) ++mex;
        int cur = 0;
        vector<int> b, ans;
        for(int i : a) {
            cnt2[i] += 1;
            b.push_back(i);
            while(cnt2[cur]) ++cur;
            if(cur == mex) {
                ans.push_back(cur);
                for(int j : b) {
                    cnt2[j] = 0;
                    if(--cnt[j] == 0) {
                        mex = min(mex, j);
                    }
                }
                b.clear();
                cur = 0;
            }
        }
        for(int i : a) cnt[i] = cnt2[i] = 0;
        cout << ans.size() << '\n';
        for(int i : ans) cout << i << " ";
        cout << '\n';
    }
}