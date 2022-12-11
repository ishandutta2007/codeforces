#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1<<20;

int h[N]={0},siz[21],n,m,k,x,sub[N],c[20]={0};

int main(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,0,m){
        int m1;
        scanf("%d",&m1);
        while (m1--){
            scanf("%d",&x);
            sub[x]=i;
        }
    }
    int cur=0;
    FOR(i,1,n){
        c[sub[i]]++;
        cur|=1<<sub[i];
        if (i>=k){
            h[cur]=1;
            if (c[sub[i-k+1]]==1) cur^=(1<<sub[i-k+1]);
            c[sub[i-k+1]]--;
        }
    }
    int ans=0;
    REP(i,1,1<<m){
        int tmp=i;
        while (tmp&&!h[i]){
            if (h[i^(tmp&-tmp)]) h[i]=1;
            tmp-=tmp&-tmp;
        }
        if (!h[i]) ans=max(ans,__builtin_popcount(i));
    }
    cout<<m-ans;
}