#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n;
string s;
bool ans = 1;

bool check(char c)
{
    if (c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || c == 'U' || c == 'V' || c == 'X' || c == 'T' || c == 'W' || c == 'Y')
        return 1;
    return 0;
}

int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        if (s[i] != s[n - 1 - i])
            ans = 0;
    for (int i = 0; i < n; i++)
        if (!check(s[i]))
            ans = 0;
    if (ans)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}