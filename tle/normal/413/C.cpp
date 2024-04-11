//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
int n,m;
struct problem
{
    bool xinxin;
    long long a;
}ps[1000001];
long long cp=0;
bool operator < (problem a,problem b)
{
    if(a.xinxin!=b.xinxin) return a.xinxin<b.xinxin;
    else if(!a.xinxin) return a.a<b.a;
    else return a.a>b.a;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>ps[i].a,ps[i].xinxin=0;
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        ps[t].xinxin=1;
    }
    sort(ps+1,ps+1+n);
    for(int i=1;i<=n;i++)
    {
        if(ps[i].xinxin) ps[i].a=max(ps[i].a,cp);
        cp+=ps[i].a;
    }
    cout<<cp;
    return 0;
}