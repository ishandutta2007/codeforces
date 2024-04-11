#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("bubble.inp","r",stdin)
#define OUTPUT freopen("bubble.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e15;
const int MOD=1e9+7;
const int N=5e3+10;

int n,x,a[N][2],p[N<<1];
ll f[N<<1];
int main(){
    scanf("%d%d",&n,&x);
    int m=1;
    p[1]=x;
    FOR(i,1,n)
        FOR(j,0,1){
            scanf("%d",&a[i][j]);
            p[++m]=a[i][j];
        }
    sort(p+1,p+m+1);
    m=unique(p+1,p+m+1)-p-1;
//    FOR(i,1,m) cout<<p[i]<<" \n"[i==m];
    FOR(i,1,m) f[i]=abs(p[i]-x);
    FOR(i,1,n){
        int L=lower_bound(p+1,p+m+1,a[i][0])-p,R=lower_bound(p+1,p+m+1,a[i][1])-p;
        REP(j,1,L) f[j]+=p[L]-p[j];
        FOR(j,R+1,m) f[j]+=p[j]-p[R];
        FOR(j,2,L) f[j]=min(f[j],f[j-1]);
        FORD(j,m-1,R) f[j]=min(f[j],f[j+1]);
//        FOR(j,1,m) cout<<f[j]<<" \n"[j==m];
    }
    cout<<*min_element(f+1,f+m+1);
}