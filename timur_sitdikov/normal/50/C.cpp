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
int x[maxn], y[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int xcur, ycur, x1[5], y1[5], n, i, ans;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> x[i] >> y[i];
    x1[0]=x[0]; y1[0]=y[0]-1;
    for(i=1; i<n; i++)
        if (x[i]+y[i]<=x1[0]+y1[0])
        {
            x1[0]=x[i]; y1[0]=y[i]-1;
        }
    x1[1]=x[0]; y1[1]=y[0]-1;
    for(i=1; i<n; i++)
        if (x[i]-y[i]>=x1[1]-y1[1])
        {
            x1[1]=x[i]; y1[1]=y[i]-1;
        }
    x1[2]=x[0]; y1[2]=y[0]+1;
    for(i=1; i<n; i++)
        if (x[i]+y[i]>=x1[2]+y1[2])
        {
            x1[2]=x[i]; y1[2]=y[i]+1;
        }
    x1[3]=x[0]; y1[3]=y[0]+1;
    for(i=1; i<n; i++)
        if (x[i]-y[i]<=x1[3]-y1[3])
        {
            x1[3]=x[i]; y1[3]=y[i]+1;
        }
    ans=0;
    xcur=x1[0]; ycur=y1[0];
    while(xcur-ycur<x1[1]-y1[1])
    {
        ans++;
        xcur++;
        ycur--;
    }
    if (xcur-ycur>x1[1]-y1[1]) 
        ycur++;
    while(xcur+ycur<x1[2]+y1[2])
    {
        ans++;
        xcur++;
        ycur++;
    }
    if (xcur+ycur>x1[2]+y1[2])
        xcur--;
    while(xcur-ycur>x1[3]-y1[3])
    {
        ans++;
        xcur--;
        ycur++;
    }
    if (xcur-ycur<x1[3]-y1[3])
        ycur--;
    while(xcur+ycur>x1[0]+y1[0])
    {
        ans++;
        xcur--;
        ycur--;
    }
    if (xcur+ycur<x1[0]+y1[0])
        xcur++;
    while(xcur!=x1[0])
    {
        ans++;
        xcur++;
        ycur--;
    }
    cout << ans;
}