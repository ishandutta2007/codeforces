#include <bits/stdc++.h>
 
using namespace std;
 
const int nax=400*1007;
 
const int md=1e9+7;
 
int tab[nax][2];
 
bool was[nax];
 
vector <int> pos[nax];
 
void dfs(int i)
{
    if(was[i]) return;
    was[i]=true;
    dfs(pos[tab[i][0]][0]);
    dfs(pos[tab[i][0]][1]);
    dfs(pos[tab[i][1]][0]);
    dfs(pos[tab[i][1]][1]);
}
 
void test()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        was[i]=false;
        pos[i].clear();
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i][0]);
        pos[tab[i][0]].push_back(i);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i][1]);
        pos[tab[i][1]].push_back(i);
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(!was[i]) dfs(i), cnt++;
    }
    long long ans=1;
    while(cnt--)
    {
        ans*=2;
        ans%=md;
    }
    printf("%lld\n", ans);
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}