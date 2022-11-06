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

int m[100005], mx[100005], sum[100005];
const int inf=1000000000;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, ans, cur;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> m[i];
        sum[i]=sum[i-1]+m[i];
    }
    mx[n]=abs(m[n]);
    for(i=n-1; i>=1; i--)
    {
        mx[i]=max(m[i]+mx[i+1], -(sum[n]-sum[i-1]));
    }
    ans=-inf;
    cur=0;
    for(i=0; i<n; i++)
    {
        cur-=m[i];
        ans=max(ans, cur+mx[i+1]);
    }
    cout << ans;


}