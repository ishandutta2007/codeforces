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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

const int maxn=200005;
int x[maxn], n;
int ind[3][2];

int check(int v)
{
    int i, i1, i2;
    for(i=0; i<3; i++)
    {
        ind[i][0]=0;
        ind[i][1]=n-1;
    }
    
    for(i=1; i<n && x[i]-x[0]<=v; i++);
    if (i==n)
    {
        return 1;
    }
    ind[0][1]=i-1;
    ind[1][0]=i;
    i1=i;
    for(; i<n && x[i]-x[i1]<=v; i++); 
    if (i==n)
        return 1;
    ind[1][1]=i-1;
    ind[2][0]=i;
    i2=i;
    for(; i<n && x[i]-x[i2]<=v; i++); 
    if (i==n)
        return 1;
    else return 0;
}

void output(int v, int mod)
{
    printf("%d.%d00000", v, mod*5); 
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, p, q, r;
    int mx;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> x[i];
    sort(x, x+n);
    if (check(0))
        q=0;
    else
        for(p=0, q=x[n-1]-x[1]; p+1<q;)
        {
            r=(p+q)>>1;
            if (!check(r))
                p=r;
            else q=r;
        }
    check(q);
    output(q/2, q&1);
    putchar('\n');
    for(i=0; i<3; i++)
    {
        output(x[ind[i][0]]+q/2, q&1);
        putchar(' ');
    }
}