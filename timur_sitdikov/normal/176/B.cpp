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

int m[2][2005];
char s1[4005], s2[4005];

int main()
{   

    int i, j, k, l, sum, ans=0, mod=1000000007, ind1, ind2, f;
    scanf("%s %s %d", &s1, &s2, &k);
    l=strlen(s1);
    m[0][0]=1;
    for(i=1; i<=k; i++)
    {
        ind1=1-i&1;
        ind2=i&1;
        sum=0;
        for(j=0; j<l; j++) 
        {
            sum+=m[ind1][j];
            if (sum>=mod) sum-=mod;
        }
        for(j=0; j<l; j++) 
        {
            m[ind2][j]=sum-m[ind1][j];
            if (m[ind2][j]<0) m[ind2][j]+=mod;
        }
    }
    for(i=l; i<2*l; i++) s1[i]=s1[i-l];
    for(i=0; i<l; i++)
    {
        f=0;
        for(j=i; j<i+l; j++) 
            if (s2[j-i]!=s1[j]) {f=1; break;}
        if (!f)
        {
            ans+=m[k&1][i];
            if (ans>=mod) ans-=mod;
        }
    }
    printf("%d", ans);
}