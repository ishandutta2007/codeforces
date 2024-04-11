#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,int> di;

const int inf=1e9;
const int MOD=1e9+7,BASE=1e9;
const int N=3e5+10,M=1e6;

int b[M+10],n,m,m1,x,y,p[N],ans[N];
vector <int> a[M+10];
vector <ii> q[M+10];
void add(int x,int v){
    while (x<=M){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
void solve(){
    FOR(i,1,M){
        //printf("%d\n",i);
        for(auto j:q[i]) ans[j.Y]+=get(j.X);
        for(auto j:a[i]) add(j,-1);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        add(y,1);
    }
    FOR(j,1,m){
        scanf("%d",&m1);
        FOR(i,1,m1) scanf("%d",p+i);
        p[m1+1]=M+1;
        FOR(i,0,m1) q[p[i]+1].push_back(ii(p[i+1]-1,j));
    }
    solve();
    FOR(i,1,m) printf("%d\n",n-ans[i]);
}