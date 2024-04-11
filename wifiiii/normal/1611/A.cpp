#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int iseven(char x) {
    return (x - '0') % 2 == 0;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(iseven(s.back())) cout << 0 << '\n';
        else if(iseven(*s.begin())) cout << 1 << '\n';
        else {
            int ok = 0;
            for(char c : s) {
                if(iseven(c)) ok = 1;
            }
            cout << (ok ? 2 : -1) << '\n';
        }
    }
}