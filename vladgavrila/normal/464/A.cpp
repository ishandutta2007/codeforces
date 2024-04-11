#include <cstdio>

using namespace std;

#define maxn 1010

int n, p, m, ok;
char s[maxn];

int main()
{
    scanf("%d%d\n", &n, &p);
    scanf("%s", s+1);

    s[0]=40;
    for(int i=1; i<=n; ++i)
        s[i]-='a';

    ++s[n];
    int k=n;

    while(k>0 && s[k]==p)
    {
        s[k-1]++;
        s[k]=0;
        --k;
        if(k==0)
        {
            printf("NO\n");
            return 0;
        }
    }
    ok=1;
    while(ok)
    {
        ok=0;
        for(int i=2; i<=n; ++i)
        {
            if(s[i]==s[i-1] || s[i]==s[i-2])
            {
                ok=1;
                for(int j=i+1; j<=n; ++j)
                    s[j]=0;
                ++s[i];
                while(i>0 && s[i]==p)
                {
                    s[i-1]++;
                    s[i]=0;
                    --i;
                    if(i==0)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
                break;
            }
        }
    }

    for(int i=1; i<=n; ++i)
        printf("%c", s[i]+'a');
    printf("\n");

    return 0;
}