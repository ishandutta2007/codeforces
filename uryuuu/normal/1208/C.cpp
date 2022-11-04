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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;

int a[1005][1005];
int b[10][10];


int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            b[j][(j+4+i-1)%4+1]=(j-1)*4+i;
        }
    }
    int s=0;
    for(int i=1;i<=n;i+=4)
    {
        for(int j=1;j<=n;j+=4,s+=16)
        {
            for(int x=1;x<=4;x++)
            {
                for(int y=1;y<=4;y++)
                {
                    a[x+i-1][y+j-1]=b[x][y]+s;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
//    for(int i=1;i<=n;i++)
//    {
//        int s=0;
//        for(int j=1;j<=n;j++)
//            s^=a[i][j];
//        cout<<s<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        int s=0;
//        for(int j=1;j<=n;j++)
//            s^=a[j][i];
//        cout<<s<<' ';
//    }
//    cout<<endl;
    return 0;
}