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
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int a[301000];
ll f[301000][5];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n+1;i++)
    {
        for(int j=0;j<5;j++)
            for(int k=0;k<=j;k++)
            {
                f[i][j]=max(f[i-1][k],f[i][j]);
            }
        f[i][1]+=a[i];
        f[i][2]+=1ll*a[i]*m;
        f[i][3]+=a[i];
        
    }
    cout<<f[n+1][4]<<endl;
    return 0;
}