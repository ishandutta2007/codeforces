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

const int maxn=1005;
char good[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int m, n, i, j, d, ans;
    string s1, s2, s3, s4;
    cin >> n >> m;
    for(i=1; i<=n; i++)
        good[i]=1;
    for(i=0; i<m; i++)
    {
        cin >> s1 >> s2 >> s3 >> s4 >> d;
        if (s3[0]=='l')
        {
            for(j=d; j<=n; j++)
                good[j]=0;
        }
        else
        {
            for(j=1; j<=d; j++)
                good[j]=0;
        }
    }
    ans=0;
    for(i=1; i<=n; i++)
        ans+=good[i];
    if (ans==0)
    {
        cout << "-1";
        return 0;
    }
    cout << ans;
}