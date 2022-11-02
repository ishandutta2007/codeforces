#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ok = 0;
    int ans = 0;
    for (int i=0;i<s.size();i++) for (int j=i+1;j<s.size();j++) for (int k=j+1;k<s.size();k++) {
        if ((100*(s[i]-'0')+10*(s[j]-'0')+s[k]-'0')%8==0) ok = 1, ans = 100*(s[i]-'0')+10*(s[j]-'0')+s[k]-'0';
    }
    for (int i=0;i<s.size();i++) for (int j=i+1;j<s.size();j++) {
        if ((10*(s[i]-'0')+s[j]-'0')%8==0) ok = 1, ans = 10*(s[i]-'0')+s[j]-'0';
    }
    for (int i=0;i<s.size();i++) {
        if ((s[i]-'0')%8==0) ok = 1, ans = s[i]-'0';
    }
    if (ok) cout << "YES\n" << ans;
    else cout << "NO";

    return 0;
}