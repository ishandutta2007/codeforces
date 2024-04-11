#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
char s[200001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int noww = 0, nowd = 0, mina = 0, maxd = 0, maxw = 0, mins = 0, sa = 0, sd = 0, sw = 0, ss = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'W')
            {
                noww++;
            }
            if (s[i] == 'S')
            {
                noww--;
            }
            if (s[i] == 'D')
            {
                nowd++;
            }
            if (s[i] == 'A')
            {
                nowd--;
            }
            checkmax(maxw, noww);
            checkmin(mins, noww);
            checkmax(maxd, nowd);
            checkmin(mina, nowd);
            checkmax(sw, noww - mins);
            checkmax(ss, maxw - noww);
            checkmax(sd, nowd - mina);
            checkmax(sa, maxd - nowd);
        }
        long long x[2], y[2];
        x[0] = max(sw, ss);
        x[1] = max((long long)(sw or ss), x[0] - !(sw == ss));
        y[0] = max(sd, sa);
        y[1] = max((long long)(sd or sa), y[0] - !(sd == sa));
        printf("%lld\n", min((x[0] + 1) * (y[1] + 1), (x[1] + 1) * (y[0] + 1)));
    }
    return 0;
}