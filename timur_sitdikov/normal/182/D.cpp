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

long long hsh[200005], rem[200005], mod=997;
char s[2][100005], ss[200005];
vector<int> v1, v2;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, l[2], n, lim, a, b, f, ans=0;
    long long tmp;
    scanf("%s %s", &s[0], &s[1]);
    l[0]=strlen(s[0]); l[1]=strlen(s[1]);
    for(i=0; i<l[0]; i++) ss[i]=s[0][i];
    for(i=0; i<l[1]; i++) ss[i+l[0]]=s[1][i];
    n=l[0]+l[1];
    rem[0]=rem[1]=1;
    for(i=1; i<=n; i++)
    {   
        hsh[i]=hsh[i-1]+rem[i-1]*ss[i-1];
        rem[i]=rem[i-1]*mod;
    }
    for(i=1; i<=l[0]; i++)
        if (!(l[0]%i) && !(n%i))
        {
            lim=n/i; f=0;
            for(j=1; j<lim; j++)
            {
                a=j*i+1; b=(j+1)*i;
                tmp=hsh[b]-hsh[a-1];
                if (hsh[i]*rem[a-1]!=tmp) f=1;
            }
            if (!f) 
                ans++;
        }
    printf("%d", ans);
}