#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 500010

int n, m, k;
int ch, a1, a2;
char s[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d\n", &n, &k);
    scanf("%s", s);

    if(k==2)
    {
        for(int i=0; i<n; ++i)
        {
            if(s[i]!='A'+i%2)
                ++a1;
            else
                ++a2;
        }
        printf("%d\n", min(a1, a2));
        if(a1<a2)
        {
            for(int i=0; i<n; ++i)
                printf("%c", 'A'+i%2);
        }
        else
        {
            for(int i=0; i<n; ++i)
                printf("%c", 'A'+1-i%2);
        }
        printf("\n");
        return 0;
    }

    for(int i=0; i<n-1; ++i)
    {
        if(s[i]==s[i+1])
        {
            ++ch;
            s[i+1]='A';
            while(s[i+1]==s[i] || s[i+1]==s[i+2])
                ++s[i+1];
        }
    }
    printf("%d\n%s\n", ch, s);

    return 0;
}