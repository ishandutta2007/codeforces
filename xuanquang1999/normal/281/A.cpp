#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s[1005]; s[0] = 0;
    cin.get(s, 1005);

    s[0] = toupper(s[0]);

    cout << s;
}