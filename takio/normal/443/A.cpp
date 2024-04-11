#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

char s[10010];
int u[30];

int main () {
    gets(s);
    int l = strlen (s);
    for (int i = 0; i < l; i++)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ' ' && s[i] != ',')u[s[i] - 'a'] = 1;
    }
    int res = 0;
    for (int i = 0; i < 27; i++)
        if (u[i]) res++;
    cout << res;
}