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

const int maxn=100005;
long long x[2][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, i, j, k, ans=0, s, s1;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> x[0][i] >> x[1][i];
    for(j=0; j<2; j++)
        sort(x[j], x[j]+n);
    for(j=0; j<2; j++)
    {
        s=0;
        s1=0;
        for(i=0; i<n; i++)
        {
            s+=x[j][i]*x[j][i];
            s1+=x[j][i];
        }
        ans+=s*(n-1);
        s1*=s1;
        s1-=s;
        ans-=s1;
    }
    cout << ans;

}