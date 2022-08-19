#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int N = (int)1e6 + 100;
map<char, char> m;
int n;
char s[N];
char st[N];
int sz;

bool isOpening(char c)
{
    return m.count(c) > 0;
}
bool arePair(char c1, char c2)
{
    return m[c1] == c2;
}

int main()
{
    m['('] = ')';
    m['['] = ']';
    m['<'] = '>';
    m['{'] = '}';

    scanf(" %s ", s);
    n = strlen(s);
    sz = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (isOpening(s[i]))
            st[sz++] = s[i];
        else
        {
            if (sz == 0)
            {
                printf("Impossible\n");
                return 0;
            }
            sz--;
            if (!arePair(st[sz], s[i])) ans++;
        }
    }
    if (sz == 0)
        printf("%d\n", ans);
    else
        printf("Impossible\n");

    return 0;
}