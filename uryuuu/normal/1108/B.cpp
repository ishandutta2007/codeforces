//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1000005;

int father[30010];
int size[30010];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

//struct node
//{
//    int l,r
//}a[10];
int a[200];
int vis[200];
int v[10005];
int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int d=a[n-1];
    for(int i=0;i<n;i++)
    {
        if(d%a[i]==0&&v[a[i]]==0)
        {
            vis[i]=1;
            v[a[i]]=1;
        }
    }
    int e=1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            e=a[i];
        }
    }
    cout<<d<<' '<<e<<endl;
    return 0;
}