#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

double p[1005][1005];

int main()
{   

    int w, b, i, j;
    scanf("%d %d", &w, &b);
    for(i=1; i<=w; i++)
        if ((w+b-i)%3==0 || (w+b-i)%3==2)
            p[i][0]=1.;
        else p[i][0]=0.;
    for(i=1; i<=w; i++)
        for(j=1; j<=b; j++)
        {
            if ((w+b-i-j)%3==0) p[i][j]=(double)i/(double)(i+j)+(double)j/(double)(i+j)*p[i][j-1];
            else if ((w+b-i-j)%3==1) p[i][j]=(double)j/(double)(i+j)*p[i][j-1];
            else p[i][j]=(double)i/(double)(i+j)*p[i-1][j]+(double)j/(double)(i+j)*p[i][j-1];
        }
    printf("%.12lf", p[w][b]);
}