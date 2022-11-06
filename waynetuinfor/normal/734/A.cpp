#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int n, a, d;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a++;
        if (s[i] == 'D') d++;
    }
    if (a > d) puts("Anton");
    else if (a == d) puts("Friendship");
    else puts("Danik");
    return 0;
}