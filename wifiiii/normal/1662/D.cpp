#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(string s) {
    string t; int b = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'A') {
            if(!t.empty() && t.back() == 'A') t.pop_back();
            else t += 'A';
        } else if(s[i] == 'C') {
            if(!t.empty() && t.back() == 'C') t.pop_back();
            else t += 'C';
        } else {
            b ^= 1;
        }
    }
    if(b) t += 'B';
    return t;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        cout << (f(a) == f(b) ? "YES" : "NO") << '\n';
    }
}