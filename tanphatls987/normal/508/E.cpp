#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=6e2+10,spe=10000;


int n,h[N][N],t[N][N];
ii br[N];
string ans;
void trace(int L,int R,int pos){
    if (L>R) return;
    if (t[L][R]==spe) {
        ans[pos]='(',ans[pos+2*(R-L)+1]=')';
        trace(L+1,R,pos+1);
    }else{
        trace(L,t[L][R],pos);
        trace(t[L][R]+1,R,pos+2*(t[L][R]-L+1));
    }
}
string solve(){
    if (!h[0][n-1]) return "IMPOSSIBLE";
    ans.resize(2*n);
    trace(0,n-1,0);
    return ans;
}
int main(){
    cin>>n;
    REP(i,0,n) {
        int L,R;
        cin>>L>>R;
        br[i]=ii(L/2,(R-1)/2);
    }
    //REP(i,0,n) printf("%d %d\n",br[i].X,br[i].Y);
    FORD(i,n-1,0){
        h[i][i]=(br[i].X==0);
        if (h[i][i]) t[i][i]=spe;
        REP(j,i+1,n){
            REP(k,i,j){
                int good=h[i][k]&&h[k+1][j];
                h[i][j]|=good;
                if (good) t[i][j]=k;
            }
            int ok=(j-i>=br[i].X)&&(j-i<=br[i].Y)&&h[i+1][j];
            h[i][j]|=ok;
            if (ok) t[i][j]=spe;
        }
    }
    //REP(i,0,n)
        //REP(j,i,n) printf("%d %d %d %d\n",i,j,h[i][j],t[i][j]);
    cout<<solve();
}