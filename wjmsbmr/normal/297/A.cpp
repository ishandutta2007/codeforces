#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
char s[N],t[N];int n,m;
int main()
{
    scanf("%s%s",s,t);
    n=strlen(s),m=strlen(t);
    int S=0;
    for(int i=0;i<n;i++)
        if(s[i]=='1')S++;
    if(S&1)S++;
    for(int i=0;i<m;i++)
        if(t[i]=='1')S--;
    if(S>=0)puts("YES");
    else puts("NO");
    return 0;
}