/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=200100;
struct Node
{
    string s;
    int id;
}q[V];
bool cmp(Node x,Node y)
{
    return x.s<y.s;
}
int n,pos[V],p[V];
bool check()
{
    int pre=-1;
    for(int i=0;i<n;i++)
    {
        int id=p[i]-1;
        int tmp=3*n;
        if(pos[id]>pre)tmp=min(tmp,pos[id]);
        if(pos[id+n]>pre)tmp=min(tmp,pos[id+n]);
        if(tmp==3*n)return false;
        pre=tmp;
    }
    return true;
}
char s[120];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            q[i].s=s;q[i].id=i;
            scanf("%s",s);
            q[i+n].s=s;q[i+n].id=i+n;
        }
        for(int i=0;i<n;i++)scanf("%d",&p[i]);
        sort(q,q+2*n,cmp);
        for(int i=0;i<2*n;i++)pos[q[i].id]=i;
        if(check())puts("YES");
        else puts("NO");
    }
    return 0;
}