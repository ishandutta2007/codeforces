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

int f[105];
const int inf=1000000000;
vector<int> ans;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, s, i, j, k;
    cin >> s >> k;
    f[0]=1;
    if (k>100)
    {
        for(i=1; ;i++)
        {
            f[i]=f[i-1]*2;
            if (f[i]>inf)
                break;
        }
    }
    else
    {
        for(i=1; ;i++)
        {
            for(j=max(0, i-k); j<i; j++)
                f[i]+=f[j];
            if (f[i]>inf)
                break;
        }
    }
    for(; s; )
    {
        for(i=0; f[i]<=s; i++);
        ans.pb(f[i-1]);
        s-=f[i-1];  
    }
    if (ans.size()==1)
        ans.pb(0);
    cout << ans.size() << endl;
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i] << " ";
}