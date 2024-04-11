#include <iostream>
#include <string>
using namespace std;

char letters[26];

void solve()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int letter = 0;
    
    string s;
    for (int i = 0; i < n && i < a % b; ++i) s.push_back(letters[letter]);
    for (int i = (int)s.size(), j = 0; i < a; ++i, ++j) {
        if (j < a / b) s.push_back(letters[letter]);
        else {
            j = 0;
            letter = (letter + 1) % 26;
            s.push_back(letters[letter]);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%c", s[i % a]);
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < 26; ++i) letters[i] = 'a' + i;
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}