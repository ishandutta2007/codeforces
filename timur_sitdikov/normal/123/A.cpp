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

char c1[1005], c2[1005], del[1005];
int num[200];

int main()
{   

    int i, j, l, mx=0, maxi;
    scanf("%s", &c1);
    l=strlen(c1);
    for(i=0; i<l; i++)
        num[c1[i]]++;
    for(i=l; i>=1; i--) c1[i]=c1[i-1];
    for(i=0; i<150; i++)
        if (num[i]>mx) {mx=num[i]; maxi=i;}
    num[150]=1;
    for(i=2; 2*i<=l; i++)
        if (!c2[i])
        {
            for(j=i; j<=l; j+=i)
            {
                if (!c2[j])
                {
                    c2[j]=maxi;
                    mx--;
                }
            } 
        }
    num[maxi]=mx;
    if (mx<0) {printf("NO"); return 0;}
    for(j=i=1; i<=l; i++)
    {
        for(; !num[j]; j++);
        if (!c2[i]) 
        {c2[i]=j; num[j]--;}
    }
    for(i=0; i<l; i++) c2[i]=c2[i+1];
    c2[l]=0;
    printf("YES\n%s", c2);
}