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
const int N=1e2+10;

int test,n,m,h[N][3],a[3][N];
string s[3];
string solve(){
    memset(h,0,sizeof(h));
    FOR(i,0,2) if (s[i][0]=='s'){
        s[i][0]='.';
        h[0][i]=1;
    }
    FOR(i,0,2)
        REP(j,0,N) a[i][j]=(j<n)?(s[i][j]=='.'):1;
    REP(turn,0,n) {
        if (turn*3>=n) return count(h[turn],h[turn]+3,1)?"YES":"NO";
//        printf("%d\n",turn);
//        FOR(i,0,2) cout<<h[turn][i]<<" \n"[i==2];
        REP(i,0,3) if (h[turn][i])
            for(int j=-1;j<=1;j++) if (i+j>=0&&i+j<3&&a[i][3*turn+1]&&a[i+j][3*turn+1]&&a[i+j][3*turn+3]) h[turn+1][i+j]=1;
    }
    return "NO";
}
int main(){
    cin>>test;
    while (test--){
        cin>>n>>m;
        FOR(i,0,2) cin>>s[i];
        cout<<solve()<<'\n';
    }
}