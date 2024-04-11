#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(s.size());
    int cnt = 0;
    for(int i = 0; i+2 < s.size(); ++i) {
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            a[i] = 1;
            ++cnt;
        }
    }
    while(q--) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int p; char c;
        cin >> p >> c;
        --p;
        for(int i = max(p-2, 0); i <= p && i+2<s.size(); ++i) {
            cnt -= a[i];
        }
        s[p] = c;
        for(int i = max(p-2, 0); i <= p && i+2<s.size(); ++i) {
            if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }for(int i = max(p-2, 0); i <= p && i+2<s.size(); ++i) {
            cnt += a[i];
        }
        cout << cnt << '\n';
    }
}