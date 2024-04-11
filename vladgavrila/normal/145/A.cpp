#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, t1, t2;
char s1[maxn], s2[maxn];

int main()
{
   // freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);

    scanf("%s", s1);
    scanf("%s", s2);

    n=strlen(s1);
    for(int i=0; i<n; ++i)
    {
        if(s1[i]=='4' && s2[i]=='7')
            ++t1;
        if(s1[i]=='7' && s2[i]=='4')
            ++t2;
    }

    printf("%d\n", max(t1, t2));
    return 0;
}