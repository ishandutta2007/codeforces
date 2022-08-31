#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = (int)2e6 + 300;
char s[N], p[N];
int pi[N];
int n;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d %s %s ", &n, s, p);
    n--;
    reverse(s, s + n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N')
            s[i] = 'S';
        else if (s[i] == 'S')
            s[i] = 'N';
        else if (s[i] == 'W')
            s[i] = 'E';
        else if (s[i] == 'E')
            s[i] = 'W';
    }
    for (int i = 0; i < n; i++)
        s[n + i] = p[i];
    for (int i = 1; i < 2 * n; i++)
    {
        pi[i] = pi[i - 1];
        while(pi[i] > 0)
        {
            if (s[i] == s[pi[i]])
            {
                pi[i]++;
                break;
            }
            pi[i] = pi[pi[i] - 1];
        }
        if (pi[i] == 0 && s[0] == s[i])
            pi[i] = 1;
    }

    /*
    s[2 * n] = (char)0;
    printf("%s\n", s);
    for (int i = 0; i < 2 * n; i++)
        printf("%d ", pi[i]);
    printf("\n");
    */

    int x = pi[2 * n - 1];
    while(x > 0)
    {
        if (x <= n)
        {
            printf("NO\n");
            return 0;
        }
        x = pi[x - 1];
    }
    printf("YES\n");

    return 0;
}