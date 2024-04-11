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

const int maxn=1<<21;
set<int> last[2];
set<int>::iterator it;
char good[maxn];
int a[100005];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, i, j, ans;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
    {
        j=i&1;
        last[1-j].clear();
        for(it=last[j].begin(); it!=last[j].end(); it++)
            last[1-j].insert((*it)|a[i]);
        last[1-j].insert(a[i]);
        for(it=last[1-j].begin(); it!=last[1-j].end(); it++)
            good[*it]=1;
    }
    ans=0;
    for(i=0; i<maxn; i++)
        ans+=good[i];
    cout << ans;
}