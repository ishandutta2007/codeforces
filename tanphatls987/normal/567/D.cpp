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
const int N=2e5+10;

int link[N][2],p[N],a[N],n,m,siz,k;
void setlink(int x,int y){
    link[x][1]=y;
    link[y][0]=x;
}
int cal(int dis){
    return dis/(siz+1);
}
int solve(){
    FOR(i,1,m) p[i]=a[i];
    sort(p+1,p+m+1);
    p[m+1]=n+1;
    int ccap=0,ans=-1;
    FOR(i,1,m+1) ccap+=cal(p[i]-p[i-1]);
    FOR(i,0,m) setlink(i,i+1);
    FORD(ph,m,1){

        if (ccap<k) ans=ph;
        int sel=lower_bound(p+1,p+m+1,a[ph])-p;
        int L=link[sel][0],R=link[sel][1];
        ccap+=cal(p[R]-p[L])-cal(p[sel]-p[L])-cal(p[R]-p[sel]);
        setlink(L,R);
//        cout<<ph<<" "<<sel<<" "<<ccap<<'\n';
    }
    return ans;
}
void prepare(){
    scanf("%d%d%d%d",&n,&k,&siz,&m);
    FOR(i,1,m) scanf("%d",a+i);
}
int main(){
    prepare();
    cout<<solve();
}