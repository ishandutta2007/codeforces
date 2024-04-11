#include <bits/stdc++.h>
using namespace std;

char cmd[100005];

int main()
{
    long long n; int q;
    scanf("%lld%d",&n,&q);
    for (int j = 0; j < q; j++)
    {
        long long s;
        scanf("%lld%s",&s,cmd);

        for (int i = 0; cmd[i]; i++)
        {
            if (cmd[i] == 'U')
            {
                if (s == (n + 1) / 2) continue;
                else
                {
                    long long f;
                    for (f = 1; (f & s) == 0; f <<= 1);
                    s = (s & ~(f * 3)) | (f << 1);
                }
            }
            else if (cmd[i] == 'L')
            {
                if (s & 1) continue;
                else
                {
                    long long f;
                    for (f = 1; (f & s) == 0; f <<= 1);
                    s = s - f + f / 2;
                }
            }
            else
            {
                if (s & 1) continue;
                else
                {
                    long long f;
                    for (f = 1; (f & s) == 0; f <<= 1);
                    s = s + f / 2;
                }
            }
        }

        printf("%lld\n", s);
    }
}