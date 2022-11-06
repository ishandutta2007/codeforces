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

long long st2[100];

long long val (long long a)
{
    int i;
    long long ans=0, tmp, tmp1;
    for(i=0; st2[i]<=a; i++)
    {
        tmp=a%st2[i+1];
        tmp1=(st2[i+1]-1)/2;
        if (tmp>tmp1 && (tmp-tmp1)&1) ans^=st2[i];
    }
    tmp=a/2;
    if (tmp&1) ans^=1;
    return ans;
}

int main()
{   
    int i, n;
    long long ans=0, tmp, tmp1, tmp2, a, m, bg=(long long)1e18;
    for(tmp=1, i=0; tmp<bg; tmp*=2, i++)
        st2[i]=tmp;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%I64d %I64d", &a, &m);
        tmp1=val(a-1);
        tmp2=val(a+m-1);
        ans^=tmp1;
        ans^=tmp2;
    }
    if (ans) printf("tolik");
    else printf("bolik");
    /*for(i=1; i<100; i++)
        printf("%d %I64d\n", i, val((long long)i));*/
}