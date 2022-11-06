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

int a[300], b[300];
vector<pair<int , int> > ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, k, n;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
        cin >> b[i];
    for(i=0; i<n; i++)
        if (a[i]!=b[i])
        {
            for(j=i+1; b[j]!=a[i]; j++);
            for(k=j-1; k>=i; k--)
            {
                ans.pb(mp(k, k+1));
                swap(b[k], b[k+1]);
            }
        }
    cout << ans.size() << endl;
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;

}