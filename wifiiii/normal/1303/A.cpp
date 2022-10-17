#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.find('1') == string::npos) cout << 0 << endl;
        else {
            int pos = find(s.begin(), s.end(), '1') - s.begin();
            while(s.back() == '0') s.pop_back();
            int cnt = 0;
            for(int i = pos; i < s.size(); ++i) {
                if(s[i] == '0') ++cnt;
            }
            cout << cnt << endl;
        }
    }
}