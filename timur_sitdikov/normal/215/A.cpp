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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int a[1000], b[1000], i, j, mn=0, n, m, mini=0;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> a[i];
    cin >> m;
    for(j=0; j<m; j++)
        cin >> b[j];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if (!(b[j]%a[i])) 
            {
                if (b[j]/a[i]>mn)
                {
                    mini=1;
                    mn=b[j]/a[i];
                }
                else if (b[j]/a[i]==mn)
                    mini++;
            }
    cout << mini;


}