#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int p[110];
int n,m;
inline int find(int x)
{return x == p[x] ? x : p[x] = find(p[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i = 1; i <= n; i++)p[i] = i;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d",&x,&y);
        p[find(x)] = find(y);
    }
    int cnt(0);
    for(int i = 1; i <= n; i++)
        if(i == find(i))
            cnt++;
    if(cnt == 1 && m == n)
        puts("FHTAGN!");
    else 
        puts("NO");
    return 0;
}