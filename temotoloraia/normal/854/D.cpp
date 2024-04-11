#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N=100005,M=1000000;
int n,m,k;
vector<pair<pair<int,int>,ll> >V[M+5];
ll mas1[M+5],mas2[M+5];
bool fix[N+5];
ll a[N+5];
ll Sum;
ll ans=-1;
int nn;
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a1,a2,a3,a4;
        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
        V[a1].pb(mp(mp(a2,a3),a4));
    }
    for (int i=1;i<=M;i++)sort(V[i].begin(),V[i].end());
    for (int i=1;i<=n;i++)
        a[i]=0,fix[i]=0;
    Sum=0;
    nn=0;
    for (int i=M;i>=1;i--){
        mas2[i]=-1;
        for (int j=0;j<V[i].size();j++)
            if(V[i][j].F.F==0){
                if (fix[V[i][j].F.S]==0)
                    nn++;
                ll x=V[i][j].S-a[V[i][j].F.S];
                if (x<0 || fix[V[i][j].F.S]==0){
                    Sum+=V[i][j].S-a[V[i][j].F.S];
                    a[V[i][j].F.S]=V[i][j].S;
                }
                fix[V[i][j].F.S]=1;
            }
        if (nn<n)
            continue;
        mas2[i]=Sum;
    }
    for (int i=1;i<=n;i++)
        a[i]=0,fix[i]=0;
    Sum=0;
    mas1[0]=-1;
    nn=0;
    for (int i=1;i<=M;i++){
        mas1[i]=-1;
        for (int j=0;j<V[i].size();j++)
            if(V[i][j].F.S==0){
                if (fix[V[i][j].F.F]==0)
                    nn++;
                ll x=V[i][j].S-a[V[i][j].F.F];
                if (x<0 || fix[V[i][j].F.F]==0){
                    Sum+=V[i][j].S-a[V[i][j].F.F];
                    a[V[i][j].F.F]=V[i][j].S;
                }
                fix[V[i][j].F.F]=1;
            }
        if (nn<n)
            continue;
        mas1[i]=Sum;
    }
    for (int i=1;i<=M-k-1;i++)
        if (mas1[i]!=-1 && mas2[i+k+1]!=-1)
            if (ans==-1 || ans>mas1[i]+mas2[i+k+1])
                ans=mas1[i]+mas2[i+k+1];
    cout<<ans<<endl;
    return 0;
}