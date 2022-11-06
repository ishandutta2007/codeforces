#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 100010
#define maxl 32

int n, n1, n2, cs, rez, x;
int rf[maxl][maxl];
char c1, chs, c2, s1[maxn], s2[maxn], sol[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%s", s1);
    scanf("%s", s2);
    n1=strlen(s1);
    n2=strlen(s2);
    if(n1!=n2)
    {
        printf("-1\n");
        return 0;
    }
    scanf("%d\n", &n);
    for(int i=0; i<=25; ++i)
    {
        for(int j=0; j<=25; ++j)
            rf[i][j]=1000000000;
        rf[i][i]=0;
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%c %c %d\n", &c1, &c2, &cs);
        rf[c1-'a'][c2-'a']=min(cs, rf[c1-'a'][c2-'a']);
    }
    for(int k=0; k<=25; ++k)
        for(int i=0; i<=25; ++i)
            for(int j=0; j<=25; ++j)
                rf[i][j]=min(rf[i][j], rf[i][k]+rf[k][j]);
    for(int i=0; i<n1; ++i)
    {
        x=1000000000;
        for(int j=0; j<=25; ++j)
        {
            if(rf[s1[i]-'a'][j]+rf[s2[i]-'a'][j]<x)
            {
                chs=j+'a';
                x=rf[s1[i]-'a'][j]+rf[s2[i]-'a'][j];
            }
        }
        if(x==1000000000)
        {
            printf("-1\n");
            return 0;
        }
        rez+=x;
        sol[i]=chs;
    }
    printf("%d\n", rez);
    for(int i=0; i<n1; ++i)
        printf("%c", sol[i]);
    printf("\n");
    return 0;
}