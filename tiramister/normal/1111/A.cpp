#include <iostream>
#include <set>
#include <string>

using namespace std;

set<char> vowel = {'a', 'i', 'u', 'e', 'o'};

int main() {
    string s[2];
    for (int i = 0; i < 2; ++i) {
        cin >> s[i];
        for (char& c : s[i]) {
            if (vowel.count(c)) {
                c = 'a';
            } else {
                c = 'b';
            }
        }
    }
    cout << (s[0] == s[1] ? "Yes" : "No") << endl;
    return 0;
}