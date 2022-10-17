#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '?') {
                int j = find_if(s.begin() + i, s.end(), [](char c) {return c != '?';}) - s.begin();
                if(i) {
                    for(int k = i; k < j; ++k) {
                        if(s[k-1] == 'R') s[k] = 'B';
                        else s[k] = 'R';
                    }
                } else {
                    for(int k = j - 1; k >= i; --k) {
                        if(k+1 < n && s[k+1] == 'R') s[k] = 'B';
                        else s[k] = 'R';
                    }
                }
            }
        }
        cout << s << endl;
    }
}