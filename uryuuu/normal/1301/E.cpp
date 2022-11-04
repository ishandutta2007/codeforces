#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;

char mp[505][505];
int s[5][505][505];
int n,m,q;
int jc(int x,int a,int b,int c,int d)
{
    return s[x][c][d]-s[x][c][b-1]-s[x][a-1][d]+s[x][a-1][b-1];
}

int r1[maxn],c1[maxn],r2[maxn],c2[maxn];
int ans[maxn];
int main()
{
    sync;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<4;k++)
                s[k][i][j]=s[k][i-1][j]+s[k][i][j-1]-s[k][i-1][j-1];
            if(mp[i][j]=='R')
                s[0][i][j]++;
            else if(mp[i][j]=='G')
                s[1][i][j]++;
            else if(mp[i][j]=='Y')
                s[2][i][j]++;
            else
                s[3][i][j]++;
        }
    }
    for(int i=1;i<=q;i++)
        cin>>r1[i]>>c1[i]>>r2[i]>>c2[i];
    for(int i=1;i<=250;i++)
    {
        if(n<2*i||m<2*i)
            break;
        for(int j=1;j<=n-2*i+1;j++)
        {
            for(int k=1;k<=m-2*i+1;k++)
                s[4][j][k]=0;
        }
        for(int j=i;j<=n-i;j++)
        {
            for(int k=i;k<=m-i;k++)
            {
               if(jc(0,j-i+1,k-i+1,j,k)==i*i&&jc(1,j-i+1,k+1,j,k+i)==i*i&&
               jc(2,j+1,k-i+1,j+i,k)==i*i&&jc(3,j+1,k+1,j+i,k+i)==i*i)
                   s[4][j-i+1][k-i+1]=1;
            }
        }
        for(int j=1;j<=n-2*i+1;j++)
        {
            for(int k=1;k<=m-2*i+1;k++)
                s[4][j][k]+=s[4][j-1][k]+s[4][j][k-1]-s[4][j-1][k-1];
        }
        for(int j=1;j<=q;j++)
            if(r2[j]-r1[j]+1>=2*i&&c2[j]-c1[j]+1>=2*i&&jc(4,r1[j],c1[j],r2[j]-2*i+1,c2[j]-2*i+1))
                ans[j]=i;
    }
    for(int i=1;i<=q;i++)
        cout<<4*ans[i]*ans[i]<<endl;
    return 0;
}