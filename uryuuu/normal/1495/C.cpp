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
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


string s;
int a[505][505];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=m;j++)
            {
                if(s[j-1]=='.')
                    a[i][j]=0;
                else
                    a[i][j]=1;
            }
        }
        int id;
        if(n%3==0)
        {
            for(int i=2;i<=n;i++)
            {
                if(i%3==2)
                {
                    for(int j=1;j<=m;j++)
                        a[i][j]=1;
                }
                else if(i%3==0)
                {
                    id=0;
                    for(int j=1;j<=m;j++)
                        if(a[i][j]==1)
                        {
                            id=j;
                        }
                    if(id==0)
                    {
                        if(i+1<=n)
                        {
                            for(int j=1;j<=m;j++)
                                if(a[i+1][j]==1)
                                {
                                    id=j;
                                }
                            if(id==0)
                                id=1;
                        }
                        else
                            id=1;
                    }
                    a[i][id]=1;
                }
                else
                {
                    id=0;
                    for(int j=1;j<=m;j++)
                        if(a[i-1][j]==1)
                        {
                            id=j;
                        }
                    a[i][id]=1;
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(i%3==1)
                {
                    for(int j=1;j<=m;j++)
                        a[i][j]=1;
                }
                else if(i%3==2)
                {
                    id=0;
                    for(int j=1;j<=m;j++)
                        if(a[i][j]==1)
                        {
                            id=j;
                        }
                    if(id==0)
                    {
                        if(i+1<=n)
                        {
                            for(int j=1;j<=m;j++)
                                if(a[i+1][j]==1)
                                {
                                    id=j;
                                }
                            if(id==0)
                                id=1;
                        }
                        else
                            id=1;
                    }
                    a[i][id]=1;
                }
                else
                {
                    id=0;
                    for(int j=1;j<=m;j++)
                        if(a[i-1][j]==1)
                        {
                            id=j;
                        }
                    a[i][id]=1;
                }
            }
        }
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                    cout<<'X';
                else
                    cout<<'.';
            }
            cout<<endl;
        }
        
        
    }
    return 0;
}

/*
1
5 9
X...X...X
..X...X..
X...X...X
..X...X..
X...X...X
 */