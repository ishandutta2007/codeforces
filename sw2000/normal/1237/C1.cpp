#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

double dis[maxn][maxn];
double x[maxn],y[maxn],z[maxn];
bool vis[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dis[i][j]=dis[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        int id;
        double mi=99999999999999999999999999999;
        for(int j=i+1;j<n;j++)
        {
            if(!vis[j]&&mi>dis[i][j])
            {
                id=j;
                mi=dis[i][j];
            }
        }

        cout<<i+1<<' '<<id+1<<endl;
        vis[id]=1;
    }

    return 0;
}