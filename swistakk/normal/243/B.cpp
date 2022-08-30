#include <iostream>
#include <vector>
#define N 100005
using namespace std;
int zaj[N];
vector<int> slo[N];
int deg[N];
int tail[N];
int zonk[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, h, t;
    cin>>n>>m>>h>>t;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]>=h+1)
        {
            for(int j=0; j<slo[i].size(); j++)
            {
                zonk[slo[i][j]]=i;
            }
            for(int j=0; j<slo[i].size(); j++)
            {
                int v=slo[i][j];
                if(deg[v]>=t+1)
                {
                    int com=0;
                    for(int k=0; k<slo[v].size(); k++)
                    {
                         if(zonk[slo[v][k]]==i)
                         {
                                com++;
                         }
                    }
                    if(deg[i]+deg[v]>=h+t+com+2)
                    {
                        cout<<"YES"<<endl;
                        cout<<i<<" "<<v<<endl;
                        int liczt=0;
                        for(int k=0; k<slo[v].size(); k++)
                        {
                            if(zonk[slo[v][k]]!=i && slo[v][k]!=i && liczt<t)
                            {
                                liczt++;
                                tail[slo[v][k]]=1;
                            }
                        } 
                        for(int k=0; k<slo[v].size(); k++)
                        {
                            if(zonk[slo[v][k]]==i && liczt<t)
                            {
                                liczt++;
                                tail[slo[v][k]]=1;
                            }
                        }
                        int liczh=0;
                        for(int  k=0; k<slo[i].size(); k++)
                        {
                            if(tail[slo[i][k]]==0 && liczh<h && slo[i][k]!=v)
                            {
                                cout<<slo[i][k]<<" ";
                                liczh++;
                            }
                        }
                        cout<<endl;
                        for(int k=1; k<=n; k++)
                        {
                            if(tail[k]==1)
                            {
                                cout<<k<<" ";
                            }
                        }
                        cout<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}