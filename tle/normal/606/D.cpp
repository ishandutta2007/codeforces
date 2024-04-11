#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,m,A[2333333],B[2333333];
bool f[2333333];
struct edg {int x,m,id;}es[2333333];
bool cx(edg a,edg b)
{
    if(a.x!=b.x) return a.x<b.x; else return a.m>b.m;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&es[i].x,&es[i].m), es[i].id=i;
    sort(es+1,es+1+m,cx);
    int cv=2,a=1,b=3;
    for(int i=1;i<=m;i++)
    {
        if(es[i].m)
        {
            A[es[i].id]=1; B[es[i].id]=cv;
            f[cv]=1; ++cv;
        }
        else
        {
            ++a; if(a==b) a=2, ++b;
            if(!f[b])
            {
                printf("-1\n"); return 0;
            }
            A[es[i].id]=a; B[es[i].id]=b;
        }
    }
    for(int i=1;i<=m;i++) printf("%d %d\n",A[i],B[i]);
}