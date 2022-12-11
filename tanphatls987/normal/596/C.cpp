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
const int N=2e5+10,zero=1e5+5;

int w[N],a[N][2],n,h[N];
vector <int> v[N],e[N];
vector <ii> c[N];

ii ans[N];
bool comp(int x,int y){
    return a[x][0]<a[y][0];
}
void prepare(){
    int x,y;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&x,&y);
        a[i][0]=x,a[i][1]=y;
        e[zero+y-x].push_back(i);
    }
    FOR(i,1,n){
        scanf("%d",&x);
        v[x+zero].push_back(i);
    }
}
void solve(){
    REP(i,0,N) {
        sort(e[i].begin(),e[i].end(),comp);
        if (e[i].size()!=v[i].size()){
            printf("NO");
            return;
        }
        int m1=v[i].size();
        REP(j,0,m1){
            int cx=e[i][j];
            int idx=v[i][j];
            w[cx]=idx;
            ans[idx]=ii(a[cx][0],a[cx][1]);
        }
    }
//    printf("tick\n");
    FOR(pha,0,1){
        REP(i,0,N) c[i].clear();
        FOR(i,1,n) c[a[i][pha]].push_back(ii(a[i][pha^1],i));
        REP(i,0,N){
            sort(c[i].begin(),c[i].end());
            int m1=int(c[i].size());
            REP(j,1,m1) if (w[c[i][j].Y]<w[c[i][j-1].Y]){
                printf("NO");
                return;
            }
        }
    }
    printf("YES\n");
    FOR(i,1,n) printf("%d %d\n",ans[i].X,ans[i].Y);
}
int main(){
    prepare();
    solve();
}