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
const int N=30;

int xa,ya,xb,yb,f[2][N][2];
vector <ii> p[2][N];
int main(){
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    FOR(type,0,1){
        FORD(i,N-1,0){
            if (xa){
                if (xa<=(1<<i)&&ya>=(1<<i)){
                    f[type][i][0]=(1<<i)-xa+1;
                    f[type][i][1]=ya-(1<<i)+1;
                    p[type][i].push_back(ii(f[type][i][0],f[type][i][1]));
                    xa=0;
                }else if (xa>(1<<i)) xa-=(1<<i),ya-=(1<<i);
            }
            FORD(j,N-1,i+1)
                FOR(k,0,1) {
                    if (f[type][j][k]>(1<<i)){
                        f[type][i][k]=max(f[type][i][k],min(f[type][j][k]-(1<<i),(1<<i)));
                        ii cur=ii(1<<i,min(f[type][j][k]-(1<<i),(1<<i)));
                        if (!k) swap(cur.X,cur.Y);
//                        printf("%d %d %d %d %d %d\n",type,j,i,k,cur.X,cur.Y);
                        p[type][i].push_back(cur);
                    }
                    if (f[type][j][k^1]>(1<<i)){
                        f[type][i][k]=(1<<i);
                        ii cur=ii(1<<i,min(f[type][j][k^1]-(1<<i),1<<i));
                        if (k) swap(cur.X,cur.Y);
//                        printf("%d %d %d %d %d %d\n",type,j,i,k,cur.X,cur.Y);
                        p[type][i].push_back(cur);
                    }
                }
        }
        xa=xb,ya=yb;
    }
    int ans=0;
    REP(i,0,N)
        for(auto j1:p[0][i])
            for(auto j2:p[1][i]) ans=max(ans,min(j1.X,j2.X)+min(j1.Y,j2.Y)-1);
    cout<<ans;
}