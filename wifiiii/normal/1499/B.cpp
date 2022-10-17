#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ok = 0;
        for(int i = 0; i < s.size(); ++i) {
            // [0,i) [i,n)
            vector<int> a;
            for(int j = 0; j < i; ++j) {
                if(s[j] == '1') a.push_back(j);
            }
            for(int j = i; j < s.size(); ++j) {
                if(s[j] == '0') a.push_back(j);
            }
            int okk = 1;
            for(int j = 1; j < a.size(); ++j) if(a[j] - a[j-1] == 1) okk = 0;
            if(okk) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}