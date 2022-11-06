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
int m1[maxn], m2[maxn], m3[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, p, f;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> m1[i];
    for(p=1; p<n; p++)
        if (m1[p]<m1[p-1])
            break;
    if (p==n)
    {
        cout << "YES";
        return 0;
    }
    for(i=0; i<p; i++)
        if (m1[i]>m1[p])
            break;
    swap(m1[i], m1[p]);
    for(j=1; j<n; j++)
        if (m1[j]<m1[j-1])
            break;
    if (j==n)
    {
        cout << "YES";
        return 0;
    }
    swap(m1[i], m1[p]);
    for(i=n-1; m1[i]>=m1[p-1]; i--);
    swap(m1[i], m1[p-1]);
    for(j=1; j<n; j++)
        if (m1[j]<m1[j-1])
            break;
    if (j==n)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}