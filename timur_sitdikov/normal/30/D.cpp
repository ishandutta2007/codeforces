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
using namespace std;

long long abs(long long v)
{return v<0? -v: v;}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, k, i, ind, ind_n, j;
    long long x, y, mn, mx;
    double ans=1e+10, cur, d1, d2;
    cin >> n >> k;
    vector<pair<long long, int> > pt(n);
    for(i=0; i<n; i++)
    {
        cin >> pt[i].first;
        pt[i].second=i; 
    }
    n--; 
    k--;
    sort(pt.begin(), pt.end());
    cin >> x >> y;  
    for(i=0; i<n; i++)
        if (pt[i].second==k)
            break;
    ind=i;
    if (k==n+1)
    {
        ans=pt[n].first-pt[0].first;
        cur=min(abs(x-pt[0].first), abs(pt[n].first-x));
        ans+=sqrt(cur*cur+y*y);
        printf("%.12lf", ans);
        return 0;
    }
    if (!y)
    {
        mn=min(x, pt[0].first);
        mx=max(x, pt[n].first);
        ans=mx-mn+min(mx-pt[ind].first, pt[ind].first-mn);
        printf("%.12lf", ans);
        return 0;
    }
    d1=pt[n].first-pt[ind].first+pt[n].first-pt[0].first;
    cur=abs(pt[0].first-x);
    d1+=sqrt(cur*cur+y*y);
    d2=pt[ind].first-pt[0].first+pt[n].first-pt[0].first;
    cur=abs(pt[n].first-x);
    d2+=sqrt(cur*cur+y*y);
    ans=min(d1, d2);
    for(i=0; i<=ind; i++)
    {
        d1=pt[n].first-pt[ind].first+pt[n].first-pt[i].first;
        cur=abs(pt[i].first-x);
        d1+=sqrt(cur*cur+y*y);      
        d2=pt[ind].first-pt[i].first+pt[n].first-pt[i].first;
        cur=abs(pt[n].first-x);
        d2+=sqrt(cur*cur+y*y);
        d1=min(d1, d2);
        j=max(0, i-1);
        cur=min(abs(x-pt[0].first), abs(x-pt[j].first));
        d1+=sqrt(cur*cur+y*y);
        d1+=pt[j].first-pt[0].first;
        ans=min(ans, d1);
    }
    for(i=ind; i<=n; i++)
    {
        d1=pt[ind].first-pt[0].first+pt[i].first-pt[0].first;
        cur=abs(pt[i].first-x);
        d1+=sqrt(cur*cur+y*y);      
        d2=pt[i].first-pt[ind].first+pt[i].first-pt[0].first;
        cur=abs(pt[0].first-x);
        d2+=sqrt(cur*cur+y*y);
        d1=min(d1, d2);
        j=min(n, i+1);
        cur=min(abs(x-pt[n].first), abs(x-pt[j].first));
        d1+=sqrt(cur*cur+y*y);
        d1+=pt[n].first-pt[j].first;
        ans=min(ans, d1);
    }
    printf("%.12lf", ans);
}