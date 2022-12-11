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
const int MOD=1e9+7;
const int N=2e5+10;
const double eps=1e-12;
int n;
ll p[N],len,v1,v2;
di a[N];
double prob[N];

void solve(){
    for(int i=n+1,L=1;i<=2*n;i++){
        while (len*v2<=(v1+v2)*(p[i]-p[L])) L++;
        a[i]=di(p[i]-(len*v2+.0)/(v1+v2),i-L+1);
        if (a[i].X>2*len) a[i].X-=2*len;
//        printf("%d %.15f %d\n",i,a[i].X,a[i].Y);
    }
    for(int i=1,R=1;i<=n;i++){
        while (len*v2>=(v1+v2)*(p[R+1]-p[i])) R++;
        a[i]=di(p[i],R-i);
//        printf("%d %.15f %d\n",i,a[i].X,a[i].Y);
    }
    sort(a+1,a+2*n+1);
    a[2*n+1]=di(a[1].X+2*len,a[1].Y);
    FOR(i,1,2*n) prob[a[i].Y]+=(a[i+1].X-a[i].X)/len;
    FOR(i,0,n) printf("%.10f\n",prob[i]/2);
}
int main(){
//    INPUT;
    scanf("%d%I64d%I64d%I64d",&n,&len,&v1,&v2);
    FOR(i,1,n) scanf("%I64d",p+i);
    FOR(i,n+1,2*n) p[i]=p[i-n]+2*len;
    //FOR(i,1,n*2) cout<<p[i]<<" \n"[i==2*n];
    solve();
}