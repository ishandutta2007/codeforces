#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int lst = 0, cnt = 0, ok = 1;
        for(int i = 0; i < s1.size(); ++i) {
            cnt += s1[i] == '1' ? 1 : -1;
            if(cnt == 0) {
                int diff = 0;
                for(int j = lst; j <= i; ++j) {
                    diff += s1[j] != s2[j];
                }
                if(diff > 0 && diff < i - lst + 1) {
                    ok = 0;
                    break;
                }
                lst = i + 1;
            }
        }
        int diff = 0;
        for(int i = lst; i < s1.size(); ++i) {
            diff += s1[i] != s2[i];
        }
        if(diff > 0 && diff < s1.size() - lst + 1) {
            ok = 0;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}