#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=2e5+10;

int w,h,n,x;
ll ans[2]={0},r[N];
ii a[N],link[2][N];
char c;
vector <int> p[2];
int main(){
    scanf("%d%d%d",&w,&h,&n);
    FOR(i,1,n){
        scanf("\n%c%d",&c,&x);
        a[i]=ii(c=='H',x);
        p[c=='H'].push_back(x);
    }
    FOR(i,0,1) p[i].push_back(0);
    p[0].push_back(w);
    p[1].push_back(h);
    FOR(i,0,1) sort(p[i].begin(),p[i].end());
    FOR(i,0,1)
        REP(j,0,int(p[i].size())) {
            link[i][j]=ii(j-1,j+1);
            if (j) ans[i]=max(ans[i],1LL*p[i][j]-p[i][j-1]);
        }
    r[n]=ans[0]*ans[1];
    FORD(i,n,2){
        int j=a[i].X,x=lower_bound(p[j].begin(),p[j].end(),a[i].Y)-p[j].begin();
        ans[j]=max(ans[j],1LL*p[j][link[j][x].Y]-p[j][link[j][x].X]);
        link[j][link[j][x].X].Y=link[j][x].Y;
        link[j][link[j][x].Y].X=link[j][x].X;
        r[i-1]=ans[0]*ans[1];
        //printf("%d %lld %lld\n",i,ans[0],ans[1]);
    }
    FOR(i,1,n) printf("%lld\n",r[i]);
}