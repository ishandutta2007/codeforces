#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n;
string s;

int main()
{
    cin >> s;
    n = s.length();
    if (n < 5)
    {
        printf("Too weak\n");
        return 0;
    }
    bool good = 0;
    for (int i = 0; i < n; i++)
        good |= (s[i] >= '0' && s[i] <= '9');
    if (!good)
    {
        printf("Too weak\n");
        return 0;
    }
    good = 0;
    for (int i = 0; i < n; i++)
        good |= (s[i] >= 'A' && s[i] <= 'Z');
    if (!good)
    {
        printf("Too weak\n");
        return 0;
    }
    good = 0;
    for (int i = 0; i < n; i++)
        good |= (s[i] >= 'a' && s[i] <= 'z');
    if (!good)
    {
        printf("Too weak\n");
        return 0;
    }
    printf("Correct\n");
    return 0;
}