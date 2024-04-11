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
const int V=100100;
struct Node{int va,id;}q[V];
int a[V];
bool cmp(Node x,Node y)
{
    if(x.va!=y.va)return x.va<y.va;
    else return x.id<y.id;
}
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i].va);
            a[i]=q[i].va;
            q[i].id=i;
        }
        sort(q,q+n,cmp);
        int df=0;
        for(int i=0;i<n;i++)
        if(q[i].va!=a[i])df++;
        if(df>2)puts("NO");
        else puts("YES");
    }
}