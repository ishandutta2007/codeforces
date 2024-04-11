#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string x1, x2;
        int p1, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        while(x1.back() == '0') x1.pop_back(), ++p1;
        while(x2.back() == '0') x2.pop_back(), ++p2;
        int len1 = x1.size() + p1, len2 = x2.size() + p2;
        if(len1 != len2) {
            if(len1 > len2) cout << ">";
            else if(len1 < len2) cout << "<";
        } else {
            if(x1 > x2) cout << ">";
            else if(x1 < x2) cout << "<";
            else cout << "=";
        }
        cout << '\n';
    }
}