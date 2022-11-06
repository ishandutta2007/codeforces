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

int dis (int x1, int y1, int x2, int y2)
{return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}

int main()
{   

    int x[3], y[3], x1[3], y1[3], i, i1, j, k, d[6];
    for(i=0; i<3; i++) scanf("%d %d", &x[i], &y[i]);
    d[3]=d[0]=dis(x[0], y[0], x[1], y[1]);
    d[4]=d[1]=dis(x[2], y[2], x[1], y[1]);
    d[5]=d[2]=dis(x[0], y[0], x[2], y[2]);
    if (d[0] && d[1] && d[2])
    {
        for(i=0; i<3; i++)
            if (d[i]==d[i+1]+d[i+2]) {printf("RIGHT\n"); return 0;}
    }
    for(i=0; i<3; i++)
    {
        
        for(j=0; j<3; j++) 
        {x1[j]=x[j]; y1[j]=y[j];}
        for(j=-1; j<2; j++)
            for(k=-1; k<2; k++)
                if (abs(j+k)==1)
                {
                    x1[i]+=j; y1[i]+=k;
                    d[3]=d[0]=dis(x1[0], y1[0], x1[1], y1[1]);
                    d[4]=d[1]=dis(x1[2], y1[2], x1[1], y1[1]);
                    d[5]=d[2]=dis(x1[0], y1[0], x1[2], y1[2]);
                    if (d[0] && d[1] && d[2])
                    {
                        for(i1=0; i1<3; i1++)
                            if (d[i1]==d[i1+1]+d[i1+2]) {printf("ALMOST\n"); return 0;}
                    }
                    x1[i]-=j; y1[i]-=k;
                }
    }
    printf("NEITHER\n"); 
}