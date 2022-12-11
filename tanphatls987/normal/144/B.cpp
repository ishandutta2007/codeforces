#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=2e3+20,zero=1e3+5;

int h[N][N];
int sqr(int x){
    return x*x;
}
int sqrdist(ii a,ii b){
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}
void prepare(){
    int xa,ya,xb,yb,xc,yc,r,m;
    cin>>xa>>ya>>xb>>yb;
    if (xa>xb) swap(xa,xb);
    if (ya>yb) swap(ya,yb);
    xa+=zero,xb+=zero,ya+=zero,yb+=zero;
//    cout<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<'\n';
    cin>>m;
    while (m--){
        scanf("%d%d%d",&xc,&yc,&r);
        xc+=zero;yc+=zero;
        FOR(i,ya,yb) if (abs(i-yc)<=r){
            int len=int(sqrt(r*r-sqr(i-yc)));
            h[i][max(xc-len,0)]++;
            h[i][min(xc+len+1,N-1)]--;
//            printf("%d %d %d %d\n",xc-len-zero,i-zero,xc+len-zero,i-zero);
        }
    }
    REP(i,0,N)
        REP(j,1,N) h[i][j]+=h[i][j-1];
    int ans=0;
    FOR(i,ya,yb) ans+=(h[i][xa]==0)+(h[i][xb]==0);
    REP(i,xa+1,xb) ans+=(h[ya][i]==0)+(h[yb][i]==0);
    cout<<ans;
}
int main(){
    prepare();
}