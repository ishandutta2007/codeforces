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
const int N=1e2+5;

string s0,s1,vir;
int f[N][N][N],kmp[N],forw[N][30];
stack <char> s;
struct cord{
    int x,y,z;
    cord (int _x=0,int _y=0,int _z=0){
        x=_x;y=_y;z=_z;
    }
}t[N][N][N];
bool maximize(int &x,int y){
    if (x<y) x=y;else return 0;
    return 1;
}
void solve(){
    int n0=s0.length(),n1=s1.length(),n2=vir.length();
    ///KMP for virus
    kmp[1]=0;
    FOR(i,2,n2){
        int re=kmp[i-1];
        while (re&&vir[i-1]!=vir[re]) re=kmp[re];
        if (vir[i-1]==vir[re]) kmp[i]=re+1;
    }
    ///precalc traces
    REP(i,0,n2)
        REP(k,0,26){
            int cur=i;
            while (cur&&vir[cur]-'A'!=k) cur=kmp[cur];
            if (vir[cur]-'A'==k) cur++;
            forw[i][k]=cur;
//            printf("%d %d\n",i,k);
        }
//    printf("tick\n");
    //
    memset(f,-1,sizeof(f));
    f[0][0][0]=0;
    FOR(i,0,n0)
        FOR(j,0,n1)
            REP(k,0,n2) if (f[i][j][k]!=-1){
                if (i<n0&&maximize(f[i+1][j][k],f[i][j][k])) t[i+1][j][k]=cord(i,j,k);
                if (j<n1&&maximize(f[i][j+1][k],f[i][j][k])) t[i][j+1][k]=cord(i,j,k);
                if (i<n0&&j<n1&&s0[i]==s1[j]){
                    int cur=forw[k][s0[i]-'A'];
                    if (maximize(f[i+1][j+1][cur],f[i][j][k]+1)) t[i+1][j+1][cur]=cord(i,j,k);
                }
            }
    int sel=0;
    REP(k,0,n2) if (f[n0][n1][k]>f[n0][n1][sel]) sel=k;
    if (f[n0][n1][sel]<=0){
        printf("0");
        return;
    }
//    cout<<f[n0][n1][sel]<<'\n';
    while (n0||n1){
        cord nex=t[n0][n1][sel];
        if (f[n0][n1][sel]!=f[nex.x][nex.y][nex.z]) s.push(s0[n0-1]);
        n0=nex.x;
        n1=nex.y;
        sel=nex.z;
    }
    while (!s.empty()) printf("%c",s.top()),s.pop();
}
int main(){
    cin>>s0>>s1>>vir;
    solve();
}