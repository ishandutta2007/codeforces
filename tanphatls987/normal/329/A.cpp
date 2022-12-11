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

string s[N];
int n;
void solve(){
    bool ok=1;
    REP(i,0,n) if (count(s[i].begin(),s[i].end(),'E')==n) ok=0;
    if (ok){
        REP(i,0,n)
            REP(j,0,n) if (s[i][j]=='.') {
                printf("%d %d\n",i+1,j+1);
                break;
            }
        return;
    }
    ok=1;
    REP(j,0,n)
        REP(i,0,n) {
            if (s[i][j]=='.') break;
            if (i==n-1) ok=0;
        }
    if (ok){
        REP(j,0,n)
            REP(i,0,n) if (s[i][j]=='.'){
                printf("%d %d\n",i+1,j+1);
                break;
            }
        return;
    }
    printf("-1");
}
int main(){
    cin>>n;
    REP(i,0,n) cin>>s[i];
    solve();
}