// indeksowanie od 1 (ale sasiadow na wektorze od 0)
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#define N 100005
#define INF 1000000000000000000ll
#define uint long long int
using namespace std;
vector< pair<uint, uint> > slo[N]; // lista sasiedztwa - slo[i][j].first = j-ty sasiad i - slo[i][j].second = waga tejze krawedzi
set< pair<uint, uint> > secik;
set< pair<uint, pair<int, int> > > krusk;
uint dis[N];
int spar[N];
uint n, m;
void dijkstra(uint v) // wpisuje odleglosci od v do k w dis[k]
{
    secik.clear();
    for(int i=0; i<=n+1; i++)
    {
        dis[i]=INF;
        secik.insert(make_pair(INF, i));
    }
    dis[v]=0;
    secik.erase(make_pair(INF, v));
    secik.insert(make_pair(0, v));
    uint newv;
    uint aktv, aktdis;
    uint bla;
    while(!secik.empty())
    {
        
        aktv=(*secik.begin()).second;
        aktdis=(*secik.begin()).first;
        secik.erase(*secik.begin());
        for(int i=0; i<slo[aktv].size(); i++)
        {
            newv=slo[aktv][i].first;
            bla=aktdis+slo[aktv][i].second;
            if(dis[newv]>bla)
            {
                secik.erase(make_pair(dis[newv], newv) );
                dis[newv]=bla;
                // par[newv]=aktv;
                secik.insert(make_pair(dis[newv], newv) );
            }
        }
    }
}
int rep[N];
int find(int v)
{
    if(spar[v]==v)
    {
        return v;
    }
    else
    {
        spar[v]=find(spar[v]);
        return spar[v];
    }
}
void unionn(int v1, int v2)
{
    int r1=find(v1);
    int r2=find(v2);
    if(r1!=r2)
    {
        spar[r1]=r2;
    }
}
int port[N];
void dijkstra2() 
{
    secik.clear();
    for(int i=0; i<=n+1; i++)
    {
        if(port[i]==1)
        {
            dis[i]=0;
            spar[i]=i;
            secik.insert( make_pair(0, i));
        }
        else
        {
            dis[i]=INF;
            secik.insert(make_pair(INF, i));
        }
    }
    //dis[v]=0;
    //secik.erase(make_pair(INF, v));
    //secik.insert(make_pair(0, v));
    uint newv;
    uint aktv, aktdis;
    uint bla;
    while(!secik.empty())
    {
        
        aktv=(*secik.begin()).second;
        aktdis=(*secik.begin()).first;
        secik.erase(*secik.begin());
        for(int i=0; i<slo[aktv].size(); i++)
        {
            newv=slo[aktv][i].first;
            bla=aktdis+slo[aktv][i].second;
            if(dis[newv]>bla)
            {
                secik.erase(make_pair(dis[newv], newv) );
                dis[newv]=bla;
                spar[newv]=spar[aktv];
                secik.insert(make_pair(dis[newv], newv) );
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int v1, v2, k;
        cin>>v1>>v2>>k;
        slo[v1].push_back( make_pair(v2, k) );
        slo[v2].push_back( make_pair(v1, k) );
    }
    int por;
    cin>>por;
    for(int i=1; i<=por; i++)
    {
        int z;
        cin>>z;
        port[z]=1;
    }
    dijkstra(1);
    uint wynik=INF;
    for(int i=1; i<=n; i++)
    {
        if(port[i]==1)
        {
            wynik=min(wynik, dis[i]);
            slo[0].push_back( make_pair(i, 0) );
            rep[i]=i;
        }
        
    }
    secik.clear();
    /* for(int i=0; i<=n+1; i++)
    {
        dis[i]=INF;
        secik.insert(make_pair(INF, i));
    } */
    dijkstra2();
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<slo[i].size(); j++)
        {
            int aktv=slo[i][j].first;
            if(i>aktv || spar[i]==spar[aktv])
            {
                continue;
            }
            else
            {
                krusk.insert( make_pair( slo[i][j].second+dis[i]+dis[aktv], make_pair(spar[i], spar[aktv]) ) );
            }
        }
    }
    int licz=0;
    while(licz<por-1)
    {
        pair<uint, pair<int, int> > cos=*krusk.begin();
        krusk.erase(krusk.begin());
        int f1=find(cos.second.first);
        int f2=find(cos.second.second);
        if(f1!=f2)
        {
            wynik+=cos.first;
            unionn(f1, f2);
            licz++;
        }
    }
    cout<<wynik<<endl;
    return 0;
}