#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int d = s.back() - '0';
    printf("%d\n", d%2);

    return 0;
}