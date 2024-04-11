#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        while(t.size() && s.size() > t.size()) {
            if(s.back() == t.back()) {
                s.pop_back();
                t.pop_back();
            } else {
                if(!s.empty()) s.pop_back();
                if(!s.empty()) s.pop_back();
            }
        }
        if(!t.size() || s == t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}