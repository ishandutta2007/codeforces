#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=1e3+10;

int n,m;
char s[N][N];
vector <int> r[2][N],h[26];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("\n%s",s[i]);
}
void solve(){
    FOR(i,1,n) r[0][1].push_back(i);
    int ans=0,top=1,last=0,cur=1;
    REP(j,0,m){
        bool ok=true;
        int ntop=0;
        FOR(k,1,n) r[cur][k].clear();
        FOR(k,1,top){
            for(auto &i:r[last][k]){
                //printf("%d %d\n",i,s[i][j]-'a');
                h[s[i][j]-'a'].push_back(i);
                FOR(j1,s[i][j]-'a'+1,25) if (!h[j1].empty()){
                   ok=false;
                   break;
                }
            }
            FOR(j1,0,25) {
                if (!h[j1].empty()) r[cur][++ntop]=h[j1];
                h[j1].clear();
            }
        }
        if (ok) last=cur,cur=1-last,top=ntop;
        else ans++;
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}