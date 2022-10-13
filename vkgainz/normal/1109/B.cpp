#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
bool works(int x, string &s) {
    for(int i=x;i<s.length();i++) if(s[i]!=s[i-x]) return false;
    return true;
}
int period(string &s) {
    for(int i=1;i<=s.length();i++) {
        if(s.length()%i!=0) continue;
        if(works(i,s)) return i;
    }
    return s.length();
}
int main() {
    string s; cin >> s;
    if(s.length()%2==1) {
        bool eq = true;
        for(int i=0;i<s.length();i++) {
            if(i!=s.length()/2) eq = eq&&s[i]==s[0];
        }
        if(eq) cout << "Impossible" << endl;
        else {
            cout << 2 << endl;
        }
        return 0;
    }
    int p = period(s);
    if(p==1) {
        cout << "Impossible" << endl;
    }
    else {
        if(p%2) {
            cout << 2 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
}