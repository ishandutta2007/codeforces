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

const int d=997;
long long h[5000005], oh[5000005], st[5000005];
char c[5000005], good[5000005];

int main()
{   
    int i, l;
    long long cur=1, ans=1, v;
    scanf("%s", &c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        st[i]=cur;
        cur*=d;
    }
    h[0]=c[0];
    for(i=1; i<l; i++)
        h[i]=h[i-1]+c[i]*st[i];
    oh[0]=c[l-1];
    for(i=1; i<l; i++)
        oh[i]=oh[i-1]+c[l-1-i]*st[i];
    good[0]=1;
    for(i=1; i<l; i++)
    {
        if (i==l-1) v=oh[i];
        else v=oh[l-1]-oh[l-2-i];
        if (h[i]*st[l-1-i]==v)
        {
            good[i]=good[(i-1)>>1]+1;
            ans+=good[i];
        }
    }
    printf("%I64d", ans);
}