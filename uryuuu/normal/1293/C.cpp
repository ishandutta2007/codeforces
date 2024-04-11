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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1e9+7;

int s[4][maxn],d[4][maxn];

int main()
{
    sync;
    int n,q;
    int x,y;
    int a=0,b=0;
    cin>>n>>q;
    int f;
    while(q--)
    {
        cin>>x>>y;
        f=0;
        if(s[x][y]==0)
        {
            s[x][y]=1;
            if(x==1)
            {
                for(int i=max(1,y-1);i<=min(n,y+1);i++)
                {
                    if(s[2][i])
                    {
                        if(d[2][i]==0)
                        {
                            b++;
                        }
                        d[2][i]++;
                        d[x][y]++;
                        f=1;
                    }
                }
                if(f==1)
                {
                    a++;
                }
            }
            else
            {
                for(int i=max(1,y-1);i<=min(n,y+1);i++)
                {
                    if(s[1][i])
                    {
                        if(d[1][i]==0)
                        {
                            a++;
                        }
                        d[1][i]++;
                        d[x][y]++;
                        f=1;
                    }
                }
                if(f==1)
                {
                    b++;
                }
            }
        }
        else
        {
            s[x][y]=0;
            f=0;
            if(x==1)
            {
                for(int i=max(1,y-1);i<=min(n,y+1);i++)
                {
                    if(s[2][i])
                    {
                        d[2][i]--;
                        if(d[2][i]==0)
                            b--;
                        f=1;
                    }
                }
                if(f==1)
                {
                    a--;
                    d[x][y]=0;
                }
            }
            else
            {
                for(int i=max(1,y-1);i<=min(n,y+1);i++)
                {
                    if(s[1][i])
                    {
                        d[1][i]--;
                        if(d[1][i]==0)
                            a--;
                        f=1;
                    }
                }
                if(f==1)
                {
                    b--;
                    d[x][y]=0;
                }
            }
        }
        if(a&&b)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}