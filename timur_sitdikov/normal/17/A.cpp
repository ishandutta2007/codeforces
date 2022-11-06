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

char c[1005], mp[3005];
int p[1005], top;

int main()
{   

    int n, k, i, j, ans=0;
    scanf("%d %d", &n, &k);
    c[0]=c[1]=1;
    for(i=2; i<=n; i++)
        if (!c[i])
            for(j=i*i; j<=n; j+=i)
                c[j]=1;
    for(i=0; i<=n; i++)
        if (!c[i]) p[top++]=i;
    for(i=1; i<top; i++)
        mp[p[i]+p[i-1]+1]=1;
    for(i=0; i<=n; i++)
        if (!c[i] && mp[i]) ans++;
    if (ans>=k) printf("YES");
    else printf("NO");
}