#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int K=16,N=5010,INF=1e10;

int n[K],a[K][N],d[K],c[1<<K][K],p[1<<K][K];
bool found[1<<K];
int curc[K],curp[K];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin>>k;
    int s=0;
    map<int,int> m;
    for(int i=1;i<=k;i++)
    {
        cin>>n[i];
        for(int j=1;j<=n[i];j++)
            cin>>a[i][j],
            s+=a[i][j],
            d[i]+=a[i][j],
            m[a[i][j]]=i;
    }
    if(s%k!=0)
        cout<<"No",exit(0);
    s/=k;
    for(int i=1;i<=k;i++)
        d[i]=s-d[i];
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n[i];j++)
        {
//            cout<<i<<" "<<j<<" : \n";
            for(int t=1;t<=k;t++)
                curc[t]=curp[t]=INF;
            curc[i]=a[i][j];
            curp[i]=d[i]+a[i][j];
            int t=i;
            int mask=1<<i;
            int x;
            while(true)
            {
//                cout<<"  "<<t<<" -> "<<curc[t]<<" "<<curp[t]<<"\n";
                x=curp[t];
                t=m[x];
                if(!t||((mask>>t)&1))
                    break;
                mask|=1<<t;
                curc[t]=x;
                curp[t]=d[t]+x;
            }
            if(t==i&&x==curc[i])
            {
//                cout<<"KPYTO! "<<mask<<"\n";
                found[mask]=true;
                for(int t=1;t<=k;t++)
                    c[mask][t]=curc[t],
                    p[mask][t]=curp[t];
            }
        }
    for(int mask=0;mask<(1<<(k+1));mask+=2)
        for(int sub=mask;sub&&!found[mask];sub=(sub-1)&mask)
        {
            int lef=mask^sub;
            if(found[sub]&&found[lef])
            {
                found[mask]=true;
                for(int t=1;t<=k;t++)
                    c[mask][t]=min(c[sub][t],c[lef][t]),
                    p[mask][t]=min(p[sub][t],p[lef][t]);
            }
        }
    int full=(1<<(k+1))-2;
    if(!found[full])
        cout<<"No",exit(0);
    cout<<"Yes\n";
    for(int t=1;t<=k;t++)
    {
        cout<<c[full][t]<<" ";
        for(int l=1;l<=k;l++)
            if(p[full][l]==c[full][t])
                cout<<l<<"\n";
    }
}