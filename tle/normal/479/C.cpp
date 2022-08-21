//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
struct p
{
    int t,s;
    p(int a,int b) {t=a; s=b;}
};
bool operator < (p a,p b)
{
    if(a.t!=b.t) return a.t<b.t; else return a.s<b.s;
}
multiset<p> s;
int n,a[10001],b[10001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        s.insert(p(a[i],b[i]));
    }
    int now=-10000;
    for(multiset<p>::iterator sb=s.begin();sb!=s.end();sb++)
    {
        p r=*sb;
        if(r.s>=now) now=r.s; else now=r.t;
    }
    cout<<now;
    return 0;
}