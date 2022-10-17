#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0, res = 0;
        for(int i = 0, j = 0; i < s.size(); i = j) {
            if(s[i] == '(') {
                if(i + 1 < s.size()) {
                    j = i + 2;
                    cnt += 1;
                } else {
                    j = i + 2;
                    res = 1;
                }
            } else { 
                ++j;
                while(j < s.size() && s[j] != ')') ++j;
                if(j == s.size()) {
                    res = s.size() - i;
                } else {
                    cnt += 1;
                }
                ++j;
            }
        }
        cout << cnt << ' ' << res << '\n';
    }
}