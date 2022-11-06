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
#define point complex<double>
#define xx first
#define yy second

const int maxn=5005;
int ans[maxn][maxn], plen[maxn], plen2[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string s;
    int n, i, j, mid, q, l, r;
    cin >> s;
    n=s.length();
    for(i=0; i<n; i++)
    {
        for(j=0; ;j++)
        {
            if (i-j<0 || i+j>=n)
                break;
            if (s[i-j]!=s[i+j])
                break;
        }
        plen[i]=j;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; ;j++)
        {
            if (i-j<0 || i+j+1>=n)
                break;
            if (s[i-j]!=s[i+j+1])
                break;
        }
        plen2[i]=j;
    }
    for(i=0; i<n; i++)
        ans[i][i]=1;
    for(i=n-1; i>=0; i--)
        for(j=i+1; j<n; j++)
        {
            ans[i][j]=ans[i][j-1]+ans[i+1][j];
            if (j!=i+1)
                ans[i][j]-=ans[i+1][j-1];
            mid=(j+i)/2;
            if ((j-i+1)&1)
            {
                if (plen[mid]>=mid-i+1)
                    ans[i][j]++;
            }
            else
            {
                if (plen2[mid]>=mid-i+1)
                    ans[i][j]++;
            }
        }
    scanf("%d", &q);
    for(i=0; i<q; i++)
    {
        scanf("%d %d", &l, &r);
        l--;r--;
        printf("%d\n", ans[l][r]);
    }
}