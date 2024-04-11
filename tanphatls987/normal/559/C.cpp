#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=2e3+10,M=2e5+10;

ll fac[M],rev[M],refac[M],f[N];
ii a[N];
bool comp(ii a,ii b){
    return (a.X==b.X)?a.Y<b.Y:a.X<b.X;
}
void prepare(){
    fac[0]=1;
    REP(i,1,M) fac[i]=fac[i-1]*i%MOD;
    rev[1]=1;
    REP(i,2,M) rev[i]=MOD-rev[MOD%i]*(MOD/i)%MOD;
    refac[0]=1;
    REP(i,1,M) refac[i]=refac[i-1]*rev[i]%MOD;
}
ll C(int x,int y){
    return fac[x]*refac[y]%MOD*refac[x-y]%MOD;
}
int main(){
    prepare();
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    FOR(i,1,n) {
        scanf("%d%d",&a[i].X,&a[i].Y);
        a[i].X--;a[i].Y--;
    }
    sort(a+1,a+n+1,comp);
    a[++n]=ii(h-1,w-1);
    FOR(i,1,n){
        f[i]=C(a[i].X+a[i].Y,a[i].X);
//        printf("%d %lld\n",i,f[i]);
        REP(j,1,i) if (a[j].Y<=a[i].Y) f[i]=(f[i]-f[j]*C(a[i].X-a[j].X+a[i].Y-a[j].Y,a[i].X-a[j].X)%MOD+MOD)%MOD;
    }
//    FOR(i,1,n) printf("%d %d %lld\n",a[i].X,a[i].Y,f[i]);
    cout<<f[n];
}