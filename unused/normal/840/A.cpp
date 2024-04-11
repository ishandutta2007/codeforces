#include <bits/stdc++.h>
using namespace std;

namespace fio
{
    char buf[524288];
    char *p = buf + 524288;

    inline char readchar()
    {
        if (p == buf + 524288)
        {
            p = buf;
            fread(buf, 524288, 1, stdin);
        }
        return *p++;
    }

    inline int readint()
    {
        char ch;
        while ((ch = readchar()) < '0')
            ;

        int ret = ch - '0';
        while ((ch = readchar()) >= '0') ret = ret * 10 + ch - '0';
        return ret;
    }
}

using fio::readint;

int a[200005];
pair<int, int> b[200005];
int ans[200005];

int main()
{
    int n = readint();

    for (int i = 1; i <= n; i++) a[i] = readint();
    for (int i = 1; i <= n; i++) b[i].first = readint(), b[i].second = i;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        ans[b[i].second] = a[n - i + 1];
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    
    fflush(stdout);
    _Exit(0);
}