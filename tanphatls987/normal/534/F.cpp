#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("f.inp","r",stdin)
#define OUTPUT freopen("f.out","w",stdout)
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
const int N=22;

int p6[10],ans[N][N],a[N],b[N]={0},t[N][8000][32],g[N][8000][32],n,m;
vector <int> e[4];
int main(){
    p6[0]=1;
    FOR(i,1,5) p6[i]=p6[i-1]*6;
    scanf("%d%d",&n,&m);
    REP(i,0,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    REP(ed,0,1<<n){
        int c=0;
        REP(i,0,n) if (ed&(1<<i)){
            c++;
            while (ed&(1<<(i+1))) i++;
        }
        //printf("%d %d\n",c,ed);
        e[c].push_back(ed);
    }
    memset(t,-1,sizeof(t));
    t[0][0][0]=t[m+1][0][0]=-2;
    int des=(m+1)/2;
    REP(pos,0,des)
        REP(i,0,p6[n])
            for(auto j:e[b[pos]]) if (t[pos][i][j]!=-1)
                for(auto k:e[b[pos+1]]){
                    int cur=i;
                    REP(j1,0,n) if (!(j&(1<<j1))&&(k&(1<<j1))) cur+=p6[j1];
                    t[pos+1][cur][k]=j;
                    g[pos+1][cur][k]=i;
                    //printf("%d %d %d %d %d %d\n",pos,i,j,pos+1,cur,k);
                }
    FORD(pos,m+1,des+2)
        REP(i,0,p6[n])
            for(auto j:e[b[pos]]) if (t[pos][i][j]!=-1)
                for(auto k:e[b[pos-1]]){
                    int cur=i;
                    REP(j1,0,n) if (!(j&(1<<j1))&&(k&(1<<j1))) cur+=p6[j1];
                    t[pos-1][cur][k]=j;
                    g[pos-1][cur][k]=i;
                }
    REP(i,0,p6[n])
        for(auto j:e[b[des]]) if (t[des][i][j]!=-1)
            for(auto k:e[b[des+1]]){
                int Rig=0,tmp=i;
                bool ok=true;
                REP(j1,0,n) {
                    int rem=(a[j1]-tmp%6);
                    if ((j&k)&(1<<j1)) rem++;
                    if (tmp%6>a[j1]||rem<0||rem>5) ok=false;
                    Rig+=rem*p6[j1],tmp/=6;
                }
                //if (i==1560) printf("%d %d %d %d\n",i,j,k,Rig);
                if (ok&&t[des+1][Rig][k]==-1) ok=false;
                if (ok){
                    //printf("%d %d %d %d\n",i,j,k,Rig);
                    ii cur=ii(i,j);
                    FORD(i1,des,1){
                        REP(j1,0,n) ans[j1][i1]=((cur.Y&(1<<j1))>0);
                        cur=ii(g[i1][cur.X][cur.Y],t[i1][cur.X][cur.Y]);
                        //printf("%d %d %d\n",i1,cur.X,cur.Y);
                    }
                    cur=ii(Rig,k);
                    FOR(i1,des+1,m){
                        REP(j1,0,n) ans[j1][i1]=((cur.Y&(1<<j1))>0);
                        cur=ii(g[i1][cur.X][cur.Y],t[i1][cur.X][cur.Y]);
                        //printf("%d %d %d\n",i1,cur.X,cur.Y);
                    }
                    REP(i1,0,n){
                        FOR(j1,1,m) if (ans[i1][j1]) printf("*");else printf(".");
                        ENDL;
                    }
                    return 0;
                }
            }
}