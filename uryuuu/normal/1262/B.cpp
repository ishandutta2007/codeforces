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
const int maxn=100005;
int a[maxn],vis[maxn],b[maxn];

int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            b[i]=0;
            cin>>a[i];
        }
        b[1]=a[1];
        vis[a[1]]=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]!=a[i-1])
            {
                b[i]=a[i];
                vis[a[i]]=1;
            }
        }
//        for(int i=1;i<=n;i++)
//        cout<<b[i]<<' ';
//        cout<<endl;
        int pos=1;
        int da=a[1];
        int f=0;
        for(int i=2;i<=n;i++)
        {
            if(b[i]==0)
            {
                while(pos<=n)
                {
                    if(vis[pos]==0)
                    {
                        if(pos<da)
                        {
                            b[i]=pos;
                        }
                        else
                            f=1;
                        vis[pos]=1;
                        break;
                    }
                    pos++;
                }
                if(pos==n+1||f==1)
                {
                    f=1;
                    break;
                }
            }
            da=max(da,b[i]);
        }
        if(f==1)
            cout<<-1;
        else
            for(int i=1;i<=n;i++)
                cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}