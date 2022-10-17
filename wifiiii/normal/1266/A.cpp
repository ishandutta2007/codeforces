#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int sum = 0;
        vector<int> cnt(10);
        for(char c : s) {
            sum += c - '0';
            cnt[c - '0'] += 1;
        }
        int ok = 0;
        if(sum % 3 == 0) {
            for(int i = 2; i <= 8; i += 2) {
                if(cnt[i] && cnt[0]) ok = 1;
            }
            if(cnt[0] >= 2) ok = 1;
        }
        cout << (ok ? "red" : "cyan") << '\n';
    }
}