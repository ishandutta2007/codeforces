#include <bits/stdc++.h>
using namespace std;
string s;
bool flag;
bool check(int l, int r) { 
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
int main() {
    cin >> s;
    int l = s.size();
    for (int i = l; i >= 1; --i) {
        if (check(0, i - 1)) flag = true;
        if (s[i - 1] != '0') break;
    } 
    puts(flag ? "YES" : "NO");
}