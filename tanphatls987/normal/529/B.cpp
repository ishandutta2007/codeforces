#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

ii a[N];
int n,p[N];
bool comp(int x,int y){
    return (a[x].X-a[x].Y>a[y].X-a[y].Y);
}
ll solve(){
    ll ans=inf;
    FOR(i,1,n){
        ll H=a[i].Y,W=a[i].X;
        int use=n/2,top=0;
        FOR(j,1,n) if (j!=i){
            if (min(a[j].X,a[j].Y)>H) {
                use=-1;
                break;
            }
            if (max(a[j].X,a[j].Y)<=H) p[++top]=j;
            else if (a[j].Y>H) W+=a[j].Y,use--;
            else W+=a[j].X;
        }
        //printf("%d %d %lld\n",i,use,W);
        sort(p+1,p+top+1,comp);
        FOR(j,1,top) if (j<=use) W+=min(a[p[j]].X,a[p[j]].Y);
        else W+=a[p[j]].X;
        if (use>=0) ans=min(ans,W*H);
        use=n/2-1,top=0;
        H=a[i].X,W=a[i].Y;
        FOR(j,1,n) if (j!=i){
            if (min(a[j].X,a[j].Y)>H) {
                use=-1;
                break;
            }
            if (max(a[j].X,a[j].Y)<=H) p[++top]=j;
            else if (a[j].Y>H) W+=a[j].Y,use--;
            else W+=a[j].X;
        }
        //printf("%d %d %lld\n",i,use,W);
        sort(p+1,p+top+1,comp);
        FOR(j,1,top) if (j<=use) W+=min(a[p[j]].X,a[p[j]].Y);
        else W+=a[p[j]].X;
        if (use>=0) ans=min(ans,W*H);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    cout<<solve();
}