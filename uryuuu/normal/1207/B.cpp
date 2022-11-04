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
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;


int a[100][100],b[100][100];
struct node
{
    int x,y;
}s[3000];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int cnt=0;
    rep(i,1,n-1)
    {
        rep(j,1,m-1)
        {
            if(a[i][j]==1&&a[i+1][j]==1&&a[i+1][j+1]==1&&a[i][j+1]==1)
            {
                s[cnt].x=i;
                s[cnt++].y=j;
                b[i][j]=1;
                b[i][j+1]=1;
                b[i+1][j]=1;
                b[i+1][j+1]=1;
            }
        }
    }
    for(int k=1;k<=n;k++)
       for(int h=1;h<=m;h++)
       {
           if(a[k][h]!=b[k][h])
           {
               cout<<-1<<endl;
               return 0;
           }
       }
    cout<<cnt<<endl;
    rep(i,0,cnt-1)
    {
        cout<<s[i].x<<' '<<s[i].y<<endl;
    }
    return 0;
}