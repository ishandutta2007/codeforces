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

const int maxn=100005;
int ans[maxn], num[maxn];
pair<int, int> pr[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, a, mx;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        pr[i]=mp(a, i+1);
        num[a]++;
    }
    sort(pr, pr+n);
    for(i=2; i<=100000; i++)
        if (num[i]>num[i-1])
        {
            printf("-1");
            return 0;
        }
    mx=0;
    for(i=0; i<n; i+=j)
    {
        for(j=0; i+j<n && pr[i+j].first==pr[i].first; j++)
            ans[pr[i+j].second]=j+1;
        if (j>mx)
            mx=j;
    }
    cout << mx << endl;
    for(i=1; i<=n; i++)
        cout << ans[i] << " ";
}