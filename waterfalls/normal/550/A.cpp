#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ok = 0;
    int f = 0;
    for (int i=0;i<s.size()-1;i++) {
        if (!f && s[i]=='A' && s[i+1]=='B') f = 1, i+=1;
        else if (f && s[i]=='B' && s[i+1]=='A') ok = 1;
    }
    f = 0;
    for (int i=0;i<s.size()-1;i++) {
        if (!f && s[i]=='B' && s[i+1]=='A') f = 1, i+=1;
        else if (f && s[i]=='A' && s[i+1]=='B') ok = 1;
    }
    if (ok) cout << "YES";
    else cout << "NO";

    return 0;
}