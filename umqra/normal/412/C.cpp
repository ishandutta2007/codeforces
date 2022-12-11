#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const int N = (int)1e6;
char res[N];
char str[N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    int x = 0;
    for (int i = 0; i < N; i++)
        res[i] = '?';

    for (int i = 0; i < n; i++)
    {
        scanf(" %s", str);
        int len = strlen(str);
        x = len;
        for (int s = 0; s < len; s++)
        {
            if (str[s] != '?')
            {
                if (res[s] == '?')
                    res[s] = str[s];
                else if (res[s] != '?' && res[s] != str[s])
                    res[s] = '.';
            }   
        }
    }   

    for (int i = 0; i < x; i++)
    {
        if (res[i] == '?')
            putchar('z');
        else if (res[i] == '.')
            putchar('?');
        else
            putchar(res[i]);
    }

    return 0;
}