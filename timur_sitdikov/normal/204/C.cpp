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

const long long maxn=200005;
const long long zz=26;
char s1[maxn], s2[maxn];
long long suml[zz][maxn], sumr[zz][maxn], numl[zz][maxn], numr[zz][maxn];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long n, i, j;
    double ans, good, total;
    scanf("%I64d %s %s", &n, &s1, &s2);
    for(i=0; i<n; i++)
    {
        s1[i]-='A';
        s2[i]-='A';
    }
    for(j=0; j<zz; j++)
    {
        numl[j][0]=(s2[0]==j? 1: 0);
        for(i=1; i<n; i++)
        {
            suml[j][i]=suml[j][i-1];
            numl[j][i]=numl[j][i-1];
            if (s2[i]==j)
            {
                suml[j][i]+=i;
                numl[j][i]++;
            }
        }
        numr[j][n-1]=sumr[j][n-1]=0;
        for(i=n-2; i>=0; i--)
        {
            sumr[j][i]=sumr[j][i+1];
            numr[j][i]=numr[j][i+1];
            if (s2[i+1]==j)
            {
                sumr[j][i]+=i+1;
                numr[j][i]++;
            }
        }
    }
    good=0;
    for(i=0; i<n; i++)
    {
        good+=(i+1)*(numr[s1[i]][i]*n-sumr[s1[i]][i]);
        good+=(n-i)*(numl[s1[i]][i]+suml[s1[i]][i]);
    }
    total=0;
    for(i=1; i<=n; i++)
        total+=i*i;
    ans=(good+0.)/total;
    printf("%.12lf", ans);

}