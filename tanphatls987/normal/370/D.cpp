#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=2e3+10;

int n,m,f[N][N]={0};
char s[N][N];
int get(int xa,int ya,int xb,int yb){
    if (xa>xb||ya>yb) return 0;
    return f[xb][yb]+f[xa-1][ya-1]-f[xb][ya-1]-f[xa-1][yb];
}
int main(){
    scanf("%d%d",&n,&m);
    int Hmin=inf,Hmax=0,Wmin=inf,Wmax=0;
    FOR(i,1,n){
        scanf("\n%s",s[i]);
        FOR(j,1,m) {
            f[i][j]=f[i][j-1]+f[i-1][j]-f[i-1][j-1]+(s[i][j-1]=='w');
            if (s[i][j-1]=='w'){
                Hmin=min(Hmin,i);
                Hmax=max(Hmax,i);
                Wmin=min(Wmin,j);
                Wmax=max(Wmax,j);
            }
        }
    }
    int Slen=max(Hmax-Hmin,Wmax-Wmin);
    FOR(i,1,n-Slen)
        FOR(j,1,m-Slen) if (get(i,j,i+Slen,j+Slen)-get(i+1,j+1,i+Slen-1,j+Slen-1)==f[n][m]){
            FOR(j1,j,j+Slen){
                if (s[i][j1-1]=='.') s[i][j1-1]='+';
                if (s[i+Slen][j1-1]=='.') s[i+Slen][j1-1]='+';
            }
            FOR(i1,i,i+Slen){
                if (s[i1][j-1]=='.') s[i1][j-1]='+';
                if (s[i1][j+Slen-1]=='.') s[i1][j+Slen-1]='+';
            }
            FOR(i1,1,n) printf("%s\n",s[i1]);
            return 0;
        }
    printf("-1");
}