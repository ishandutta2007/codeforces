#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

int main()
{
    //freopen("gift.inp", "r", stdin);
    //freopen("gift.out", "w", stdout);

    char s[100];
    scanf("%s", &s); int n = strlen(s);
    fto(i, 0, n)
        for(char c = 97; c <= 122; ++c)
        {
            char t[100];
            fto(j, 0, i-1) t[j] = s[j];
            t[i] = c;
            fto(j, i+1, n) t[j] = s[j-1];

            bool ok = true;
            fto(j, 0, n/2)
                if (t[j] != t[n-j]) ok = false;
            if (!ok) continue;

            fto(j, 0, n) printf("%c", t[j]);
            return 0;
        }

    printf("NA");
    return 0;
}