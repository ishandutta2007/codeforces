#include <iostream>
#include <string>
using namespace std;

string s;
int n, a, b;

int main() {
    cin >> n >> a >> b;
    cin >> s;
    cout << (s[a - 1] == s[b - 1] ? 0 : 1) << '\n';
    return 0;
}