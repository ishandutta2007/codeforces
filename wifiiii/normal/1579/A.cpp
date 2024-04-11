#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(count(s.begin(), s.end(), 'B') * 2 == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
}