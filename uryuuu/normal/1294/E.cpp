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
const int maxn=200005;
const ll Mod=1e9+7;
 
int b[maxn];
 
int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int a[n+10][m+10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int sum=0;
    int nn=max(n*4000,(100000000/n-10)*n);
    for(int i=0;i<m;i++)
    {
        int s=9999999;
        for(int j=0;j<n;j++)
        {
            b[j]=0;
        }
        for(int j=0;j<n;j++)
        {
//            cout<<a[j][i]<<' '<<(a[j][i]-i-1)%n<<endl;
            if((a[j][i]-i-1)%m==0&&1<=a[j][i]&&a[j][i]<=m*n)
            {
//                cout<<"JL"<<' '<<i<<' '<<j<<' '<<a[j][i]<<endl;
//                cout<<(j-(a[j][i]-i-1)/m+n)%n<<endl;
                b[(j-(a[j][i]-i-1)/m+nn)%n]++;
            }
        }
        for(int j=0;j<n;j++)
        {
            b[j]=n-b[j]+j;
//            cout<<b[j]<<' ';
        }
//        cout<<endl<<endl;
        for(int j=0;j<n;j++)
        {
            s=min(s,b[j]);
        }
//        cout<<s<<endl;
        sum+=s;
    }
    cout<<sum<<endl;
    return 0;
}