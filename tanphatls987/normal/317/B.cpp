#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=0,cen=250;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};


int n,m,x,y,a[500][500]={0};
queue <ii> q;

int main(){
    scanf("%d%d",&n,&m);
    a[cen][cen]=n;
    q.push(ii(cen,cen));
    while (!q.empty()){
        int cx=q.front().X,cy=q.front().Y;
        q.pop();
        if (a[cx][cy]>=4)
            FOR(i,0,3){
                int nx=cx+dx[i],ny=cy+dy[i];
                int v=a[nx][ny]+a[cx][cy]/4;
                if (v>=4&&a[nx][ny]<4) q.push(ii(nx,ny));
                a[nx][ny]=v;
            }
        a[cx][cy]%=4;
    }
    while (m--){
        scanf("%d%d",&x,&y);
        if (abs(x)>220||abs(y)>220) printf("0\n");
        else printf("%d\n",a[x+cen][y+cen]);
    }
}