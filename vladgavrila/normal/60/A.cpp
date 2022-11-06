#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, m, i, j, k, tip, a, b;
char s[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    a=1;
    b=n;
    while(m--)
    {
        scanf("%s%s%s", s, s, s);
        if(s[0]=='l')
            tip=1;
        else
            tip=2;
        scanf("%s%d\n", s, &j);
        if(tip==1)
            b=min(b, j-1);
        else
            a=max(a, j+1);
    }
    if(a<=b)
        printf("%d\n", b-a+1);
    else
        printf("-1\n");
    return 0;
}