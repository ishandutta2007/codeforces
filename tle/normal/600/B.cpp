//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n,m,a[233333],anss[233333];
struct cb {int x,id;}b[233333];
bool operator < (cb a,cb b) {return a.x<b.x;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++) scanf("%d",&b[i].x), b[i].id=i;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int ap=1;
    for(int i=1;i<=m;i++)
    {
        while(ap<=n&&a[ap]<=b[i].x) ++ap;
        anss[b[i].id]=ap-1;
    }
    for(int i=1;i<=m;i++) printf("%d ",anss[i]);
}