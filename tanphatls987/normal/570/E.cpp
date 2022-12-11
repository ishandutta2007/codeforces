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
const int N=5e2+10;
const int dx[2]={1,0},dy[2]={0,1};

int n,m,a[N][N],f[2][N][N];
string s;
int check(int x,int y){
    return (x&&y&&x<=n&&y<=m);
}
int equa(int xa,int ya,int xb,int yb){
    return (a[xa][ya]==a[xb][yb]);
}
int main(){
    cin>>n>>m;
    FOR(i,1,n) {
        cin>>s;
        FOR(j,1,m) a[i][j]=s[j-1]-'a'+1;
    }
    f[0][1][n]=equa(1,1,n,m);
//    cout<<f[0][0][n]<<'\n';
    int ans=0,cur=0,last=1;
    REP(len,1,(n+m)/2){
        swap(cur,last);
        memset(f[cur],0,sizeof(f[cur]));
        FOR(xa,1,min(n,1+len))
            FOR(xb,max(n-len,1),n){
                int ya=len-(xa-1)+1,yb=m-(len-(n-xb));
                if (check(xa,ya)&&check(xb,yb)&&equa(xa,ya,xb,yb)){
                    FOR(k1,0,1)
                        FOR(k2,0,1){
                            int nxa=xa-dx[k1],nya=ya-dy[k1],nxb=xb+dx[k2],nyb=yb+dy[k2];

                            if (check(nxa,nya)&&check(nxb,nyb)) {
//                                printf("->%d %d %d %d %d\n",nxa,nya,nxb,nyb,f[len-1][nxa][nxb]);
                                f[cur][xa][xb]=(f[cur][xa][xb]+f[last][nxa][nxb])%MOD;
                            }
                        }
//                    printf("%d %d %d %d %d %d\n",len,xa,ya,xb,yb,f[len][xa][xb]);
                    if (len==(n+m)/2-1&&abs(xb-xa)+abs(yb-ya)<=1) ans=(ans+f[cur][xa][xb])%MOD;
                }
            }
    }
    cout<<ans;
}