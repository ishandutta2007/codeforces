#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s[105]; s[0] = 0;
    cin.get(s, 105);

    int countUpper = 0, countLower = 0, n = strlen(s);
    for(int i = 0; i < n; ++i) {
        if (isupper(s[i])) ++countUpper;
        else ++countLower;
    }

    if (countUpper > countLower) {
        for(int i = 0; i < n; ++i) s[i] = toupper(s[i]);
    } else {
        for(int i = 0; i < n; ++i) s[i] = tolower(s[i]);
    }

    cout << s;
}