#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define uint long long int
#define N 1000006
using namespace std;
vector<int> slo[N];
int ile(int a, int b)
{
    int p1=0, p2=0;
    int last=0;
    if(slo[a][p1]<slo[b][p2])
    {
        last=1;
    }
    else
    {
        last=0;
    }
    
    int wyn=0;
    
    while(p1<slo[a].size() && p2<slo[b].size())
    {
        if(slo[a][p1]<slo[b][p2])
        {
            if(last==1)
            {
                wyn++;
                last=0;
            }
            p1++;
        }
        else
        {
            if(last==0)
            {
                wyn++;
                last=1;
            }
            p2++;
        }
    }
    return wyn+1;
}
int zaj[N];
vector<int> war;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(zaj[a]==0)
        {
            zaj[a]=1;
            war.push_back(a);
        }
        slo[a].push_back(i);
    }
    int wynik=0;
    for(int i=0; i<war.size(); i++)
    {
        wynik=max(wynik, int(slo[war[i]].size()));
        // slo[war[i]].push_back(N+2);
        for(int j=0; j<i; j++)
        {
            wynik=max(wynik, ile(war[i], war[j]));
        }
    }
    //cout<<ile(10, 20)<<endl;
    cout<<wynik<<endl;
    return 0;
}