#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    map<char, int> ma;
    for(auto ch : s) ma[ch]++;

    for(int i = 0; i < ma['n']; i++) cout << 1 << " ";
    for(int i = 0; i < ma['z']; i++) cout << 0 << " ";
}