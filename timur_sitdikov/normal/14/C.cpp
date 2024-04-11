#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct point {int x,y;} pt[8];

int cmp(const void *c1, const void *c2)
{
    if (((point*)c1)->x-((point*)c2)->x) 
        return (((point*)c1)->x-((point*)c2)->x);
    return (((point*)c1)->y-((point*)c2)->y);
}

int main()
{   
  
    int i, x=0, y=0;
    for(i=0; i<4; i++)
    {
        scanf("%d %d %d %d", &pt[2*i].x, &pt[2*i].y, &pt[2*i+1].x, &pt[2*i+1].y);
        if (pt[2*i].x!=pt[2*i+1].x && pt[2*i].y!=pt[2*i+1].y) {printf("NO\n"); return 0;}
        if (pt[2*i].x!=pt[2*i+1].x) y++;
        if (pt[2*i].y!=pt[2*i+1].y) x++;
    }
    if (!(x==2 && y==2)) {printf("NO\n"); return 0;}
    qsort(pt, 8, sizeof(point), cmp);
    for(i=0; i<4; i++)
        if (pt[2*i].x!=pt[2*i+1].x || pt[2*i].y!=pt[2*i+1].y) {printf("NO\n"); return 0;}
    if (pt[0].x!=pt[2].x)  {printf("NO\n"); return 0;}
    if (pt[4].x!=pt[6].x)  {printf("NO\n"); return 0;}
    if (pt[4].x==pt[0].x)  {printf("NO\n"); return 0;}
    if (pt[2].y==pt[0].y)  {printf("NO\n"); return 0;}
    if (pt[0].y!=pt[4].y)  {printf("NO\n"); return 0;}
    if (pt[2].y!=pt[6].y)  {printf("NO\n"); return 0;}
    printf("YES\n");
}