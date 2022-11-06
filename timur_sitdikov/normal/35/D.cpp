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

pair<int, int> pr[300];

bool cmp(pair<int, int> pr1, pair<int, int> pr2)
{return pr1.first*pr1.second<pr2.first*pr2.second;}

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
   // #endif
    int n, x, i, sum;
    cin >> n >> x;
    for(i=0; i<n; i++)
    {
        cin >> pr[i].first;
        pr[i].second=n-i;
    }
    sort(pr, pr+n, cmp);
    sum=0;
    for(i=0; i<n; i++)
    {
        sum+=pr[i].first*pr[i].second;
        if (sum>x)
            break;
    }
    cout << i;
}