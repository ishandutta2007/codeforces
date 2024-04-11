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

const int lim=10000000;
int m[lim+5];

void erat()
{
    int i, j, k;
    for(i=1; i*i<=lim; i++)
    {
        k=i*i;
        for(j=k; j<=lim; j+=k)
            m[j]=k;
    }
}

int main()
{   

    long long ans=0;
    int n, a, i;
    erat();
    scanf("%d %d", &a, &n);
    for(i=a; i<a+n; i++)
        ans+=(long long)(i/m[i]);
    printf("%I64d", ans);
}