#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,k;
int a[maxn],b[maxn];
vector<int> v[maxn],A;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&b[i]);
        v[a[i]].push_back(b[i]);
    }
    int tot=0;
    for(int i=1;i<=k;++i)
    {
        if(!v[i].size())tot++;
        else if(v[i].size()>1)
        {
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size()-1;++j)A.push_back(v[i][j]);
        }
    }
    sort(A.begin(),A.end());
    ll ans=0;
    for(int i=0;i<tot;++i)ans+=1ll*A[i];
    printf("%lld\n",ans);
}