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

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

queue <int> q;
int n,a[N],link[N][2],h[N]={0};
void setlink(int x,int y){
    link[x][1]=y;
    link[y][0]=x;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n){
        link[i][0]=i-1;
        link[i][1]=i+1;
        if (a[i]<=a[i-1]&&a[i]<=a[i+1]) q.push(i);
    }
    ll ans=0;
    while (!q.empty()){
        int x=q.front();q.pop();
        if (h[x]) continue;
        h[x]=1;
        ans+=min(a[link[x][0]],a[link[x][1]]);
        setlink(link[x][0],link[x][1]);
        FOR(i,0,1){
            int nx=link[x][i];
            if (a[nx]<=a[link[nx][0]]&&a[nx]<=a[link[nx][1]]) q.push(nx);
        }
    }
    //FOR(i,1,n) cout<<h[i]<<" \n"[i==n]]
    int m=0;
    FOR(i,1,n) if (!h[i]) a[++m]=a[i];
    FOR(i,2,m-1) ans+=min(a[i+1],a[i-1]);
    cout<<ans;
}