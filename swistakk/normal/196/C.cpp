#include <iostream>
#include <algorithm>
#include <vector>
#define N 1555
#define uint long long int
using namespace std;
vector<int> slo[N];
struct p
{
    uint x;
    uint y;
};
p pkt[N];
p s; // globalny punkt wokol ktorego sortujemy katowo
uint ilow(p a, p b)
{
    return (a.x-s.x)*(b.y-s.y)-(a.y-s.y)*(b.x-s.x);
}
int czesc(p a)
{
    if(a.y!=s.y)
    return a.y<s.y;
    return a.x<s.x;
}
bool cmp(int a, int b)
{
    if(pkt[a].x==s.x && pkt[a].y==s.y)
    {
        return 1;
    }
    if(pkt[b].x==s.x && pkt[b].y==s.y)
    {
        return 0;
    }
    int cza=czesc(pkt[a]), czb=czesc(pkt[b]);
    if(cza!=czb)
    {
        return cza<czb;
    }
    else
    {
        return ilow(pkt[a], pkt[b])>0;
    }
}
/* void sortuj(int nr, int n)
{
    s=pkt[nr];
    for(int i=1; i<=n; i++)
    {
        tab[i]=i;
    }
    sort(tab+1, tab+1+n, cmp); // sortuje punkty wzgledem punktu nr i porzadek umieszcza w tab
    // pierwszym punktem bedzie s
} */

int d;
int invpre[N];
int roz[N];
int vis[N];
void dfs(int v)
{
    roz[v]++;
    d++;
    vis[v]=1;
    for(int i=0; i<slo[v].size(); i++)
    {
        int aktv=slo[v][i];
        if(vis[aktv]==0)
        {
            dfs(aktv);
            roz[v]+=roz[aktv];
        }
        
    }
}

vector<int> dziel[N];
int odp[N];
int zaj[N];
bool rozwiazuj(int root, int wek)
{
    /* cout<<root<<":root  wek:"<<wek<<endl;
    for(int i=0; i<dziel[wek].size(); i++)
    {
        cout<<dziel[wek][i]<<" ";
    }
    cout<<endl;  */
    p naj=pkt[dziel[wek][0]];
    int najnr=dziel[wek][0];
    // cout<<najnr<<endl;
    for(int i=1; i<dziel[wek].size(); i++)
    {
        p bla=pkt[dziel[wek][i]];
        if(bla.y<naj.y)
        {
            naj=bla;
            najnr=dziel[wek][i];
        }
        else
        {
            if(bla.y==naj.y)
            {
                if(bla.x<naj.y)
                {
                    naj=bla;
                    najnr=dziel[wek][i];
                }
            }
        }
    }
    odp[najnr]=root;
    s=naj;
    sort(dziel[wek].begin(), dziel[wek].end(), cmp);
    int licz=1;
    /*for(int i=0; i<slo[root].size(); i++)
    {
        int aktv=slo[root][i];
        if(roz[aktv]<roz[root])
        {
            zaj[aktv]=1;
        }
    } */
    for(int i=0; i<slo[root].size(); i++)
    {
        int aktv=slo[root][i];
        if(roz[aktv]<roz[root])
        {
            dziel[wek+1].clear();
            for(int j=0; j<roz[aktv]; j++)
            {
                /* while(zaj[dziel[wek][licz]]==1)
                {
                    licz++;
                } */
                dziel[wek+1].push_back(dziel[wek][licz]);
                //cout<<"wrzuc: "<<dziel[wek][licz]<<endl;
                licz++;
            }
            rozwiazuj(aktv, wek+1);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        slo[a].push_back(b);
        slo[b].push_back(a);
    }
    p cos;
    for(int i=1; i<=n; i++)
    {
        cin>>pkt[i].x>>pkt[i].y;
        dziel[1].push_back(i);
    }
    dfs(1);
    zaj[1]=1;
    /* for(int i=1; i<=n; i++)
    {
        cout<<roz[i]<<" ";
    } */
    rozwiazuj(1, 1); 
    
    for(int i=1; i<=n; i++)
    {
        cout<<odp[i]<<" ";
    }
    cout<<endl;
    return 0;
}