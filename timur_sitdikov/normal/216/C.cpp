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

vector<int> vv;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, i, cur;
    cin >> n >> m >> k;
    for(i=0; i<k; i++)
        vv.pb(1);
    for(; ;i++)
    {
        cur=vv[i-k]+n-1;
        if (vv[i-1]+n-1!=cur)
            cur++;
        if (cur>=n+m+1)
            break;
        else vv.pb(cur);
    }
    cout << vv.size() << endl;
    for(i=0; i<(int)vv.size(); i++)
        cout << vv[i] << " ";
}