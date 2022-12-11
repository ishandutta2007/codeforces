#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

int n,m,a[N],ans[N];
int lis[N],lds[N],always[N];
int s[N];
vector <ii> v[N];
vector <int> v2[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(ii(y,i));
    }
    int top=0;
    FOR(i,1,n){
        for(auto j:v[i])
            ans[j.Y]+=lower_bound(s+1,s+top+1,j.X)-s;
        int idx=lower_bound(s+1,s+top+1,a[i])-s;
        lis[i]=idx;
        s[idx]=a[i];
        if (idx>top) top++;
    }
    top=0;
    FORD(i,n,1){
        for(auto j:v[i])
            ans[j.Y]+=lower_bound(s+1,s+top+1,j.X,greater<int>())-s;
        int idx=lower_bound(s+1,s+top+1,a[i],greater<int>())-s;
        lds[i]=idx;
        s[idx]=a[i];
        if (idx>top) top++;
    }
    ///
}
void solve(){
    int alis=0;
    FOR(i,1,n) alis=max(alis,lis[i]+lds[i]);
    FOR(i,1,n) {
        always[i]=(lis[i]+lds[i])==alis;
        if (always[i]) v2[lis[i]].push_back(i);
    }
    FOR(i,1,n) if (v2[i].size()>1)
        for(auto j:v2[i]) always[j]=0;
    FOR(i,1,n)
        for(auto j:v[i]) ans[j.Y]=max(ans[j.Y],alis-always[i]);
    FOR(i,1,m) printf("%d\n",ans[i]-1);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}