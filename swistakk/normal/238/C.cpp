#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define uint long long int
#define N 3005
using namespace std;
int t[N];
vector< pair<int, int> > slo[N];
int vis[N];
int maxiwar;
int oddolu[N];
int dogory;
void dfs(int v)
{
    //cout<<"wtf5"<<endl;
    //system("pause");
    vis[v]=1;
    for(int i=0; i<slo[v].size(); i++)
    {
        if(vis[slo[v][i].first]==0)
        {
            if(slo[v][i].second==-1)
            {
                dogory++;
            }
            dfs(slo[v][i].first);
            oddolu[v]=max(oddolu[v], oddolu[slo[v][i].first]-slo[v][i].second);
        }
        //system("pause");
        
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a, b;
    //system("pause");
    for(int i=1; i<=n-1; i++)
    {
        cin>>a>>b;
        slo[a].push_back( make_pair(b, 1) );
        slo[b].push_back( make_pair(a, -1) );
    }
    //system("pause");
    //cout<<"5"<<endl; 
    int wyn=3005;
    for(int i=1; i<=n; i++)
    {
        dogory=0;
        for(int j=1; j<=n; j++)
        {
            vis[j]=0;
            oddolu[j]=0;
        }
        maxiwar=0;
        //system("pause");
        dfs(i);
        //system("pause");
        for(int j=1; j<=n; j++)
        {
            wyn=min(wyn, dogory-oddolu[j]);
        }
    }
    cout<<wyn<<endl;
    //system("pause");
    return 0;
}