#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    deque<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    string s;
    cin >> s;
    vector<int> ans;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(i && s[i] != s[i-1]) {
            ans.push_back(a.back());
            a.pop_back();
        } else {
            ans.push_back(a.front());
            a.pop_front();
        }
    }
    reverse(ans.begin(), ans.end());
    vector<char> pos(n);
    int res = ans[0];
    pos[0] = s[0];
    for(int i = 1; i < n; ++i) {
        if(s[i] != s[i-1]) {
            assert(ans[i] > res);
            res = ans[i] - res;
            pos[i] = s[i];
        } else {
            if(res > ans[i]) {
                res -= ans[i];
                pos[i] = s[i] == 'L' ? 'R' : 'L';
            } else {
                res += ans[i];
                pos[i] = s[i];
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " " << pos[i] << endl;
    }
}