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
const int N=1e3+10;
int a[N][N],n,m,x,y,p[N*N],s[N],h[N][N];

bool check(int x){
    memset(h,0,sizeof(h));
    REP(j,0,m){
        int top=0;
        REP(i,0,n) if (a[i][j]>=p[x]){
            FOR(k,1,top){
                h[s[k]][i]++;
                if (h[s[k]][i]>1) return 1;
            }
            s[++top]=i;
        }
    }
    return 0;
}
int solve(){
    REP(i,0,n)
        REP(j,0,m) p[i*m+j]=a[i][j];
    sort(p,p+n*m);
    int R=unique(p,p+n*m)-p-1,L=0;
    while (L<=R){
        int M=(L+R)/2;
        if (check(M)) L=M+1;
        else R=M-1;
    }
    return p[R];
}
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,n)
        REP(j,0,m) scanf("%d",&a[i][j]);
    cout<<solve();
}