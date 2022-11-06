#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 1010

int n, k;
char s[maxn];
int f[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d\n", &k);
    scanf("%s", s);
    n=strlen(s);
    for(int i=0; i<n; ++i)
        ++f[s[i]-'a'];

    for(int i=0; i<=26; ++i)
    {
        if(f[i]%k!=0)
        {
            printf("-1\n");
            return 0;
        }
    }

    for(int i=1; i<=k; ++i)
        for(int j=0; j<=26; ++j)
            for(int l=1; l<=f[j]/k; ++l)
                printf("%c", char(j+'a'));

    printf("\n");

    return 0;
}