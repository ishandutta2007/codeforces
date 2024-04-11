#include <bits/stdc++.h>
using namespace std;

const string a="aA0";

bool ok(string s) {
    bool a1=0, a2=0, a3=0;
    for(char c : s) {
        a1|=c>='a'&&c<='z';
        a2|=c>='A'&&c<='Z';
        a3|=c>='0'&&c<='9';
    }
    return a1&&a2&&a3;
}

void solve() {
    string s;
    cin >> s;
    if(ok(s)) {
        cout << s << "\n";
        return;
    }
    for(int i=0; i<s.size(); ++i) {
        char c=s[i];
        for(int j=0; j<3; ++j) {
            s[i]=a[j];
            if(ok(s)) {
                cout << s << "\n";
                return;
            }
        }
        s[i]=c;
    }
    for(int i=0; i<s.size()-1; ++i) {
        char c1=s[i], c2=s[i+1];
        for(int j=0; j<3; ++j) {
            s[i]=a[j];
            s[i+1]=a[(j+1)%3];
            if(ok(s)) {
                cout << s << "\n";
                return;
            }
        }
        s[i]=c1;
        s[i+1]=c2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}