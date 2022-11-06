#include <stdio.h>
#include <cstring>

using namespace std;

#define maxn 220

int n, i, j, k, ok, l1, l2;
char s[maxn], sol[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", s+1);
    n=strlen(s+1);
    ok=0;
    for(int i=1; i<=n; ++i)
    {
        sol[++l2]=s[i];
        if(i>2 && i<n && !ok)
        {
            if(s[i]=='t' && s[i-1]=='a')
            {
                ok=1;
                l2-=1;
                sol[l2]='@';
            }
        }
        if(i>3 && i<n)
        {
            if(s[i]=='t' && s[i-1]=='o' && s[i-2]=='d')
            {
                l2-=2;
                sol[l2]='.';
            }
        }
    }
    for(int i=1; i<=l2; ++i)
    {
        printf("%c", sol[i]);
    }
    return 0;
}