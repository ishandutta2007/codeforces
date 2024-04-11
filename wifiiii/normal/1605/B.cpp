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
        string a;
        cin >> a;
        string b = a;
        sort(b.begin(), b.end());
        if(a == b) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            vector<int> ans;
            for(int i = 0; i < a.size(); ++i) {
                if(a[i] != b[i]) ans.push_back(i);
            }
            cout << ans.size() << " ";
            for(int i : ans) cout << i + 1 << " ";
            cout << '\n';
        }
    }
}