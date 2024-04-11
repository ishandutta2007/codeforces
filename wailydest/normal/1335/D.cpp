#include <iostream>
#include <string>
using namespace std;

void solve()
{
    char s[10][10];
    for (int i = 0; i < 9; ++i) scanf("%s", s[i]);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i == 0 && j == 0 || i == 1 && j == 3 || i == 2 && j == 6 || i == 3 && j == 1 || i == 4 && j == 4 || i == 5 && j == 7 || i == 6 && j == 2 || i == 7 && j == 5 || i == 8 && j == 8) printf("%c", s[i][j] != '1' ? '1' : '2');
            else printf("%c", s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}