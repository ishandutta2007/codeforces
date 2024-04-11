#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        unordered_map<int,int> cnt;
        for(char c : s) cnt[c]++;
        int ok = 1;
        if(x > 0) {
            if(cnt['R'] < x) ok = 0;
        } else if(x < 0) {
            if(cnt['L'] < -x) ok = 0;
        }
        if(y > 0) {
            if(cnt['U'] < y) ok = 0;
        } else {
            if(cnt['D'] < -y) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}