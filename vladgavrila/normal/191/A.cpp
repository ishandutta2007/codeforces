#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 110
#define maxl 150

int n, l, dm;
int d[maxn][maxn], f[maxn][maxn];
char c1, c2, s[maxl];

int main()
{
   // freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);

    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        l=strlen(s);

        c1=s[0]-'a';
        c2=s[l-1]-'a';

        dm=0;
        for(int j=0; j<26; ++j)
        {
            if(f[j][c1]==1)
            {
                d[j][c2]=max(d[j][c1]+l, d[j][c2]);
                f[j][c2]=1;
            }
        }
        d[c1][c2]=max(d[c1][c2], l);
        f[c1][c2]=1;
    }

    dm=0;
    for(int j=0; j<26; ++j)
        dm=max(d[j][j], dm);
    printf("%d\n", dm);

    return 0;
}