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
typedef pair<ii,int> iii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=15,M=1<<16;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,len=0,h[N][N][M],t[N][N];
ii pos[N],des;
string s[N];
queue <iii> q;
bool ok(ii a){
    return (a.X>=0&&a.X<n&&a.Y>=0&&a.Y<m&&s[a.X][a.Y]!='#');
}
int relate(ii a,ii b){
    if (b.X==a.X+1) return 0;
    if (b.X==a.X-1) return 1;
    if (b.Y==a.Y+1) return 2;
    return 3;
}
int convert(){
    int ans=0;
    FORD(i,len-1,1) ans=ans*4+relate(pos[i-1],pos[i]);
    return ans;
}
void revert(ii cpos,int st){
    pos[0]=cpos;
    REP(i,1,len) {
        int dir=st%4;
        pos[i]=ii(pos[i-1].X+dx[dir],pos[i-1].Y+dy[dir]);
        st>>=2;
    }
}
void prepare(){
    cin>>n>>m;
    REP(i,0,n) cin>>s[i];
    REP(i,0,n)
        REP(j,0,m) {
            if (s[i][j]>='0'&&s[i][j]<='9') {
                pos[s[i][j]-'1']=ii(i,j);
                len=max(len,s[i][j]-'0');
            }
            if (s[i][j]=='@') des=ii(i,j);
        }
    int st=convert();
    h[pos[0].X][pos[0].Y][st]=1;
    q.push(iii(pos[0],st));
}
int solve(){
    int c=0;
    while (!q.empty()){
        ii cpos=q.front().X;
        int st=q.front().Y;q.pop();
        if (cpos.X==des.X&&cpos.Y==des.Y) return h[cpos.X][cpos.Y][st]-1;
        c++;
//        printf("%d %d %d %d\n",cpos.X,cpos.Y,st,h[cpos.X][cpos.Y][st]);
        revert(cpos,st);
//        REP(i,0,len) printf("%d %d\n",pos[i].X,pos[i].Y);
        REP(i,0,len-1) t[pos[i].X][pos[i].Y]=c;
        FOR(i,0,3){
            ii nposi=ii(cpos.X+dx[i],cpos.Y+dy[i]);
            int nst=((st%(1<<(2*len-4)))<<2)+(i^1);
            if (!ok(nposi)||t[nposi.X][nposi.Y]==c||h[nposi.X][nposi.Y][nst]) continue;
            h[nposi.X][nposi.Y][nst]=h[cpos.X][cpos.Y][st]+1;
            q.push(iii(nposi,nst));
        }
    }
    return -1;
}
int main(){
    prepare();
    cout<<solve();
}