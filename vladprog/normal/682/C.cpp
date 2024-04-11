#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,ll> pill;
typedef vector< pill > vpill;
typedef vpill::iterator vpilli;
typedef vector<vpill> vvpill;

const ll inf=1e18;
const ll z=0;

int n,k;
vi a;
vvpill r;

void dfs(int v,ll d)
{
    if(d>a[v])
    {
        for(vpilli i=r[v].begin();i!=r[v].end();i++)
            dfs(i->first,inf);
        k++;
    }
    else
        for(vpilli i=r[v].begin();i!=r[v].end();i++)
            dfs(i->first,max(z,d+i->second));
}

int main()
{
    scanf("%d",&n);
    a=vi(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    r=vvpill(n+1);
    for(int i=2;i<=n;i++)
    {
        int p,c;
        scanf("%d%d",&p,&c);
        r[p].push_back(pill(i,c));
    }
    dfs(1,0);
    printf("%d",k);
}