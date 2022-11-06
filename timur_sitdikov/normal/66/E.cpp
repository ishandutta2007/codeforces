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

const int maxn = 100005;
vector<int> good1, good2;
int col[maxn], a[maxn], b[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, cur, mn, sa, sb, ans;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> b[i];
    for(i = 0; i < n; i++)
        cin >> a[i];
    good1.pb(0);
    mn = 0; 
    sa = sb = 0;
    for(i = 0; i < n - 1; i++){
        sa += a[i];
        sb += b[i];
        cur = sb - sa;
        if (cur == mn)
            good1.pb(i + 1);
        if (cur < mn){
            mn = cur;
            good1.clear();
            good1.pb(i + 1);
        }
    }
    good2.pb(0);
    sa = sb = 0;
    mn = 0;
    for(i = n ; i > 0; i--){
        sa += a[i - 1];
        sb += b[i % n];
        cur = sb - sa;
        if (cur == mn)
            good2.pb(i - 1);
        if (cur < mn){
            mn = cur;
            good2.clear();
            good2.pb(i - 1);
        }
    }
    for(i = 0; i < (int)good1.size(); i++)
        col[good1[i]] = 1;
    for(i = 0; i < (int)good2.size(); i++)
        col[good2[i]] = 1;
    ans = 0;
    for(i = 0; i < n; i++){
        if (col[i]){
            ans++;
        }
    }
    cout << ans << endl;
    for(i = 0; i < n; i++){
        if (col[i]){
            cout << i + 1 << " ";
        }
    }
}