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

char c[105];
int main()
{   
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int n, i, j, k, k1, mx=0, f;
    scanf("%s", &c);
    n=strlen(c);
    for(i=0; i<n; i++)
        for(k=i+1; k<n; k++) 
        {
            for(k1=0; k+k1<n; k1++)
                if (c[i+k1]!=c[k+k1]) 
                {mx=max(mx, k1); break;}
            if (k+k1==n) mx=max(mx, k1);
        }
        printf("%d", mx);
}