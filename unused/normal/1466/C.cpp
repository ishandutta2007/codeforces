#include <cstdio>
using namespace std;

char z[100005];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s", z);
        int ans = 0;
        for (int i = 1; z[i]; i++)
        {
            if (z[i] == z[i-1] || (i >= 2 && z[i] == z[i-2]))
            {
                ++ans;
                z[i] = 'a';
                for (;;)
                {
                    if ((i>=2&&z[i]==z[i-2]) || z[i]==z[i-1] || z[i]==z[i+1] || z[i]==z[i+2])
                    {
                        ++z[i];
                    }
                    else break;
                }
            }
        }

        printf("%d\n", ans);
    }
}