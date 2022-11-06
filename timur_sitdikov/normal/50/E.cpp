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

const int maxn=6000005;
char used[4*maxn];
int sq[10000], top;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, n, m, b, cur, c, lim;
    long long ans=0;
    cin >> n >> m;
    for(i=1; i*i<=m; i++)
        sq[top++]=i*i;
    for(i=1; i<=n; i++)
    {
        cur=0;
        b=i;
        c=2*b-1;
        for(j=0; b>0 && c<=m; j++)
        {
            b--;
            used[-i+b+maxn]=1;
            used[-i-b+maxn]=1;          
            c+=2*b-1;
        }
        lim=m;
        if (i<=10000)
            lim=min(lim, i*i);
        ans+=(lim-j)<<1;
    }
    for(i=0; i<=2*maxn; i++)
        ans+=used[i];
    cout << ans;
}