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

char c[10000005];
pair<pair<int, int>, int > pr[105];
int ans[105];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> pr[i].first.second >> pr[i].first.first;
        pr[i].second=i;
    }
    sort(pr, pr+n);
    for(i=0; i<n; i++)
        for(j=pr[i].first.second; ; j++)
            if (!c[j])
            {
                c[j]=1;
                ans[pr[i].second]=j;
                break;
            }
    for(i=0; i<n; i++)
        cout << ans[i]  << " ";
}