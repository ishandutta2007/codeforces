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

const int maxn=105;

int a[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i, ans, tmp;
    cin >> n;
    if (n==1 || !(n&1))
    {
        printf("-1");
        return 0;
    }
    for(i=1; i<=n; i++)
        cin >> a[i];
    ans=0;
    for(i=n; i>1; i-=2)
    {
        tmp=max(a[i], a[i-1]);
        ans+=max(a[i], a[i-1]);
        a[i/2]=max(a[i/2]-tmp, 0);
        a[i]=a[i-1]=0;
    }
    ans+=a[1];
    cout << ans;
}