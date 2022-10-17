#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

int solve(string s) {
    int n = s.size(), ans = 0;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        for(int j = i; j < n; ++j) {
            if(s[j] == '1') ++cnt;
            if(cnt && (j - i + 1) % cnt == 0) ++ans;
        }
    }
    return ans;
}
string gen(int n) {
    string ret;
    for(int i=0;i<n;++i) ret+=mrand()%2+'0';
    return ret;
}

int main() {
    // for 0 <= l < r <= n
    // (pre[r] - pre[l]) | (r - l)
    // r - l = k * (pre[r] - pre[l])
    // a[r] - k * b[r] = a[l] - k * b[l]
    // k * pre[r] - r = k * pre[l] - l
    int t = 1;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pre(n + 1);
        for(int i = 0; i < n; ++i) pre[i+1] = pre[i] + (s[i] == '1');
        const int K = sqrt(n);
        vector<int> cnt(n * (K+1) + 5);
        ll ans = 0;
        // k < K
        for(int k = 1; k < K; ++k) {
            for(int i = 0; i <= n; ++i) {
                ans += cnt[k * pre[i] - i + n];
                ++cnt[k * pre[i] - i + n];
            }
            for(int i = 0; i <= n; ++i) {
                --cnt[k * pre[i] - i + n];
            }
        }
        // k >= K, pre[r] - pre[l] = (r - l) / k <= (r - l) / K
        vector<int> pos;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') pos.push_back(i);
        }
        pos.push_back(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n / K && pre[i] + j + 1 < pos.size(); ++j) {
                int l = pos[pre[i] + j], r = pos[pre[i] + j + 1] - 1;
                int count = j + 1;
                int b = i + count * K - 1;
                if(b <= r) ans += (r - b) / count + 1;
                if(b <= l - 1) ans -= (l - 1 - b) / count + 1;
            }
        }
        cout << ans << endl;
    }
}