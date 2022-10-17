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
        string s, s2;
        cin >> s >> s2;
        int f = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == '1' && s2[i] == '1') f = 1;
        }
        cout << (f ? "NO" : "YES") << '\n';
    }
}