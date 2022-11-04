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
const int maxn=200050;
int a[maxn],c[maxn];
int b[105][105];
int v[maxn];

map<int,int>mp,vis;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int m,k,pos;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
        vis[a[i]]++;
    }
    int da=a[1];
    mp[a[1]]++;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=da)
        {
            mp[a[i]]++;
            da=a[i];
        }
    }
    sort(c+1,c+n+1,cmp);
    
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        int d=c[i];
        int ss=0;
        for(int j=i;j>=1;j--)
        {
            if(c[j]==d)
                ss++;
            else
                break;
        }
        int cnt=1;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==d)
            {
                if(ss>0)
                {
                    b[i][cnt++]=a[j];
                    ss--;
                }
            }
            if(a[j]>d)
            {
                b[i][cnt++]=a[j];
            }
//            if(cnt>i)
//            {
//                cout<<'l'<<cnt<<' '<<i<<endl;
//                break;
//            }
        }
//        for(int j=1;j<cnt;j++)
//        {
//            cout<<b[i][j]<<' ';
//        }
//        cout<<endl;
    }
    while(m--)
    {
        cin>>k>>pos;
        cout<<b[k][pos]<<endl;
    }
    return 0;
}