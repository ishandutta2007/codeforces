#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1005;
const ll Mod=1e9+7;

struct node
{
    int x,y,sum;
}a[maxn];


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    int dx=a[1].x;
    int dy=a[1].y;
    for(int i=1;i<=n;i++)
    {
        a[i].x-=dx;
        a[i].y-=dy;
        a[i].sum=a[i].x+a[i].y;
    }
    
    
    while(1)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].sum%2)
            {
                cnt++;
            }
        }
        if(cnt!=0)
        {
            cout<<cnt<<endl;
            for(int i=1;i<=n;i++)
            {
                if(a[i].sum%2)
                    cout<<i<<' ';
            }
            cout<<endl;
            break;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                int xx=(a[i].x+a[i].y)/2;
                int yy=(a[i].x-a[i].y)/2;
                a[i].x=xx;
                a[i].y=yy;
                a[i].sum=a[i].x+a[i].y;
            }
        }
        
    }
    
    
    
    return 0;
}