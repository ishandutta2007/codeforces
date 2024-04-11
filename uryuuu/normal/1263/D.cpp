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
const int maxn=200005;

int father[30];

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
int v[30];
int vis[30];
int a[30];
string s;
int main()
{
    sync;
    int n;
    for(int i=0;i<28;i++)
    {
        father[i]=i;
    }
    cin>>n;
    int c,d;
    while(n--)
    {
        cin>>s;
        v[int(s[0]-'a')]=1;
        for(int i=1;i<s.length();i++)
        {
            v[int(s[i]-'a')]=1;
            c=int(s[i-1]-'a');
            d=int(s[i]-'a');
            jihe(c,d);
        }
    }
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if(v[i]==1)
        {
//            cout<<i<<endl;
            vis[getf(i)]=1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(vis[i])
        {
//            cout<<i+1<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}