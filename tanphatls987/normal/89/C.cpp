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
const int N=5e3+10;
const string dir="LDUR";
const int dx[4]={0,1,-1,0},dy[4]={-1,0,0,1};

int a[N][N]={0},n,m,Slink[N][4],link[N][4];
char s[N];
int cv(char x){
    int ans=3;
    while (ans>=0&&dir[ans]!=x) ans--;
    return ans;
}
bool inside(ii x){
    return (x.X>0&&x.X<=n&&x.Y>0&&x.Y<=m);
}
int check(ii cur){
    REP(i,0,n*m)
        FOR(k,0,3) link[i][k]=Slink[i][k];
    int ans=0,idx=(cur.X-1)*m+cur.Y-1;
    while (1){
        ans++;
        FOR(i,0,3){
            int nidx=link[idx][i];
            if (nidx==-1) continue;
            link[nidx][3-i]=link[idx][3-i];
        }
        int cx=idx/m+1,cy=idx%m+1;
        idx=link[idx][a[cx][cy]];
        if (idx==-1) break;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=cv(s[j-1]);
    }
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]!=-1){
            FOR(k,0,3){
                int cx=i+dx[k],cy=j+dy[k];
                while (a[cx][cy]==-1) cx+=dx[k],cy+=dy[k];
                Slink[(i-1)*m+j-1][k]=inside(ii(cx,cy))?((cx-1)*m+cy-1):-1;
            }
        }
    int ans=0,way=0;
    FOR(i,1,n)
        FOR(j,1,m) if (a[i][j]!=-1){
            int v=check(ii(i,j));
//            printf("%d %d %d\n",i,j,v);
            if (v>ans) ans=v,way=1;
            else if (v==ans) way++;
        }
    cout<<ans<<" "<<way;
}