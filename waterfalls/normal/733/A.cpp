#include <iostream>
using namespace std;

int n;
string s;

int main() {
    cin >> s;
    s+='A';
    n = s.size();
    int ans = 0;
    int prev = -1;
    for (int i=0;i<n;i++) {
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y') {
            ans = max(ans,i-prev);
            prev = i;
        }
    }
    cout << ans << endl;

    return 0;
}