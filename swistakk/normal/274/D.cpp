#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#define uint long long int
#define N 500005
using namespace std;
pair<int, int> wie[N];
vector<int> slo[N];
int deg[N];
int odp[N];
vector<int> kol;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    int last=m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>wie[j].first;
            wie[j].second=j;
        }
        sort(wie+1, wie+1+m);
        int wsk=1;
        if(wie[m].first==-1)
        {
            continue;
        }
        while(wsk<=m && wie[wsk].first==-1)
        {
            wsk++;
        }
        last++;
        while(wsk<=m)
        {
            int wsk2=wsk+1;
            while(wsk2<=m && wie[wsk2].first==wie[wsk].first)
            {
                wsk2++;
            }
            wsk2--;
            for(int j=wsk; j<=wsk2; j++)
            {
                slo[last].push_back(wie[j].second);
                deg[wie[j].second]++;
                slo[wie[j].second].push_back(last+1);
                deg[last+1]++;
            }
            last++;
            wsk=wsk2+1;
        }
    }
    for(int i=1; i<=last; i++)
    {
        if(deg[i]==0)
        {
            kol.push_back(i);
        }
    }
    for(int i=0; i<kol.size(); i++)
    {
        odp[i+1]=kol[i];
        int v=kol[i];
        for(int j=0; j<slo[v].size(); j++)
        {
            int aktv=slo[v][j];
            deg[aktv]--;
            if(deg[aktv]==0)
            {
                kol.push_back(aktv);
            }
        }
    }
    if(kol.size()!=last)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=1; i<=last; i++)
    {
        if(odp[i]<=m)
        {
            cout<<odp[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}