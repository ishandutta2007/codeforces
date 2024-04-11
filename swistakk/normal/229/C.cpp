#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define uint long long int
using namespace std;
uint deg[1001*1005];
int main()
{
    ios_base::sync_with_stdio(0);
    uint n, m;
    cin>>n>>m;
    uint a, b;
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    uint zle=0;
    for(int i=1; i<=n; i++)
    {
        zle+=(n-1-deg[i])*deg[i];
    }
    zle/=2;
    uint wynik=n;
    wynik*=(n-1)*(n-2);
    wynik/=6;
    cout<<wynik-zle<<endl;
    
    
    
    //system("pause");
    return 0;
}