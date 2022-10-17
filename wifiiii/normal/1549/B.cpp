#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(t[i] == '1') {
                if(s[i] == '0') {
                    ++ans;
                } else {
                    if(i && s[i-1] == '1') {
                        ++ans;
                        s[i-1] = '2';
                    } else if(i+1<n && s[i+1] == '1') {
                        ++ans;
                        s[i+1] = '2';
                    }
                }
            }
        }
        cout << ans << endl;
    }
}