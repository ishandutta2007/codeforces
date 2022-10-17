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
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        string s;
        cin >> s;
        vector<int> pr, pb;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'B') {
                pb.push_back(a[i]);
            } else {
                pr.push_back(a[i]);
            }
        }
        sort(pb.begin(), pb.end());
        sort(pr.begin(), pr.end());
        int ok = 1;
        for(int i = 0; i < pb.size(); ++i) {
            if(i > pb[i]) ok = 0;
        }
        for(int i = pb.size(), j = 0; i < n; ++i, ++j) {
            if(i < pr[j]) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}