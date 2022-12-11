#include <bits/stdc++.h>
using namespace std;

char str[55];
char used[256];
char no[256];

int main()
{
    int len, n;
    scanf("%d%s%d",&len,str,&n);
    for (int i = 0; i < len; i++)
    {
        used[str[i]] = true;
        no[str[i]] = true;
    }

    for (int i = 0; i < n; i++)
    {
        char dat[55];
        scanf("%s", dat);
        bool wrong = false;
        for (int j = 0; j < len; j++)
        {
            if (str[j] != '*' && dat[j] != str[j])
            {
                wrong = true;
                break;
            }
            if (str[j] == '*' && used[dat[j]])
            {
                wrong = true;
                break;
            }
        }

        if (wrong) continue;

        for (int j = 'a'; j <= 'z'; j++)
        {
            if (find(dat, dat + len, j) == dat + len) no[j] = true;
        }
    }

    printf("%d\n", 26 - accumulate(no + 'a', no + 'z' + 1, 0));
}