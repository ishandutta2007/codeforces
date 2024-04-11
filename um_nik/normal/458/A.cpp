#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n, m;
string s;
int a[100100], b[100100];

int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        a[n - i - 1] = (int)(s[i] - '0');
    for (int i = 100010; i >= 1; i--)
    {
        if (a[i] == 1 && a[i - 1] == 1)
        {
            a[i] = a[i - 1] = 0;
            a[i + 1] = 1;
            i += 4;
        }
    }
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        b[n - i - 1] = (int)(s[i] - '0');
    for (int i = 100010; i >= 1; i--)
    {
        if (b[i] == 1 && b[i - 1] == 1)
        {
            b[i] = b[i - 1] = 0;
            b[i + 1] = 1;
            i += 4;
        }
    }
    for (int i = 100010; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            if (a[i] > b[i])
                printf(">\n");
            else
                printf("<\n");
            return 0;
        }
    }
    printf("=\n");
    return 0;
}