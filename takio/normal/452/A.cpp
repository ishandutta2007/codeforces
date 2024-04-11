#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char s[10][10] = {"", "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main () {
    int n;
    char s2[10];
    cin >> n >> s2;
    for (int i = 1; i <= 8; i++)
    {
        if (n == strlen(s[i])){
            for (int j = 0; j < n; j++)
                if (s2[j] != '.' && s2[j] != s[i][j]) goto x;
            cout << s[i];
            x:;
        }
    }
}