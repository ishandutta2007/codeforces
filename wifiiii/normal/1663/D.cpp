#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(string s, int x) {
    if(s == "ABC" && x <= 1999) return 1;
    if(s == "ARC" && x <= 2799) return 1;
    if(s == "AGC" && x >= 1200) return 1;
    return 0;
}
int main() {
    string s;
    cin >> s;
    int x;
    cin >> x;
    cout << (check(s, x) ? "YES" : "NO") << '\n';
}