#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int num = 0;
    for (int i=0;i<n;i++) if (s[i]!=t[i]) num+=1;
    if (num%2==1) cout << "impossible\n";
    else {
        for (int i=0;i<n;i++) {
            if (s[i]==t[i]) cout << s[i];
            else {
                cout << (num%2 ? s[i] : t[i]);
                num-=1;
            }
        }
        cout << '\n';
    }

    return 0;
}