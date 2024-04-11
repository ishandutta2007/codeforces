#include <iostream>
#include <algorithm>
#include <vector>
#define uint long long int
#define N 300005
using namespace std;
vector<int> kol;
int gr[N];
vector<int> slo[N];
int wrog[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        wrog[i]=slo[i].size();
        gr[i]=1;
        if(wrog[i]>=2)
        {
            kol.push_back(i);
        }
    }
    for(int i=0;i<kol.size(); i++)
    {
        //cout<<kol[i]<<endl;
        int aktv=kol[i];
        if(wrog[aktv]>=2)
        {
            gr[aktv]=3-gr[aktv];
            for(int j=0; j<slo[aktv].size(); j++)
            {
                int newv=slo[aktv][j];
                if(gr[newv]==gr[aktv])
                {
                    wrog[newv]++;
                    wrog[aktv]++;
                    if(wrog[newv]>=2)
                    {
                        kol.push_back(newv);
                    }
                }
                else
                {
                    wrog[newv]--;
                    wrog[aktv]--;
                }
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<gr[i]-1;
    }
    cout<<endl;
    return 0;
}