#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 50010

int n, i, j, nr, k;
char c[maxn], inst[10], ch;
int coa[maxn], sol[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    while(scanf("%c", &ch)==1)
        if(ch>20)
            c[++n]=ch;
    for(int i=1; i<=n; ++i)
    {
        nr=0;
        memset(inst, 0, sizeof(inst));
        while(c[i]!='>')
        {
            inst[++nr]=c[i];
            ++i;
        }
        if(inst[2]=='t' && inst[3]=='a')
        {
            ++coa[0];
            continue;
        }
        if(inst[2]=='t' && inst[3]=='d')
        {
            coa[coa[0]]++;
            continue;
        }
        if(inst[2]=='/' && inst[3]=='t' && inst[4]=='a')
        {
            sol[++sol[0]]=coa[coa[0]];
            coa[coa[0]]=0;
            --coa[0];
            continue;
        }
    }
    sort(sol+1, sol+sol[0]+1);
    for(int i=1; i<=sol[0]; ++i)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}