#include <stdio.h>
#include <cstring>

using namespace std;

#define maxn 10010

int n, i, j, k, lg;
int l[maxn], ml[maxn];
char s[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    gets(s+1);
    k=strlen(s+1);
    l[0]=1;
    for(int i=1; i<=k; ++i)
    {
        l[l[0]]++;
        if(s[i]=='.' || s[i]=='?' || s[i]=='!')
        {
            if(l[l[0]]>n)
            {
                printf("Impossible\n");
                return 0;
            }
            l[++l[0]]=-1;
        }
    }
    ml[0]=1;
    ml[1]=l[1];
    for(int i=2; i<l[0]; ++i)
    {
        if(ml[ml[0]]+1+l[i]>n)
            ml[++ml[0]]=l[i];
        else
            ml[ml[0]]+=1+l[i];
    }
    printf("%d\n", ml[0]);
    return 0;
}