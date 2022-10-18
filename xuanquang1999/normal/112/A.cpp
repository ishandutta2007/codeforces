#include <iostream>
#include <cstring>

using namespace std;

char lower(char a[]);

int main() {
    char a[105]; a[0] = 0;
    cin.get(a, 105);
    cin.ignore(1000, '\n');

    char b[105]; b[0] = 0;
    cin.get(b, 105);
    cin.ignore(1000, '\n');

    lower(a);
    lower(b);

    cout << strcmp(a, b);
}

char lower(char a[]) {
    for(int i = 0; i < strlen(a); ++i)
        a[i] = tolower(a[i]);
}