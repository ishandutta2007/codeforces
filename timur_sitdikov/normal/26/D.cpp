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

double good_p(int m, int n)
{return (n+1-m+0.)/(n+1);}

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, k, i;
    double p=0., q=0., tmp, v=1., tmp1;
    scanf("%d %d %d", &n, &m, &k);
    if (n+k<m) {printf("0.000000000"); return 0;}
    //if (!k) {printf("%.12lf", good_p(m, n)); return 0;}
    for(i=0; i<k; i++) v=v*(m-i+0.)/(n+m-i+0.);
    for(i=0; i+k<m; i++)
    {
        if (i>=1) 
        {
            v=v*(n-i+1+0.)/(n+m-(i+i+k-2)+0.);
            v=v*(i+i+k-1+0.)/(i+0.);
            v=v*(m-i-k+1+0.)/(n+m-(i+i+k-1)+0.);
            v=v*(i+i+k+0.)/(i+k);
        }
        tmp=good_p(i, i+k);
        q+=v*tmp*(m-k-i+0.)/(m+n-k-i-i+0.); 
    }
    p=1.-q;
    printf("%.12lf", p);
}