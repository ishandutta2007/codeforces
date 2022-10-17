#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << *max_element(s.begin(), s.end()) << '\n';
    }
}