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
const int N=2e3+10;

int n,a[N][N],invr[N],invc[N];
char s[N];

int solve(){
    int ans=0;
    FORD(phase,1,0){
        memset(invr,0,sizeof(invr));
        memset(invc,0,sizeof(invc));
        for(int sel=0,sym=n-1;sel<=sym;sel++,sym--){
            FORD(i,sym,sel+phase) if (a[i][sel]^invc[sel]^invr[i]){
                invr[i]^=1;
                invc[sel]^=1;
//                printf("%d %d\n",i,sel);
                ans++;
            }
//            REP(i,0,n) printf("%d ",invr[i]);ENDL;
            FOR(j,sel+1,sym-phase) if (a[sym][j]^invr[sym]^invc[j]){
                invc[j]^=1;
                invr[sym]^=1;
//                printf("%d %d\n",sym,j);
                ans++;
            }
        }
        REP(i,0,n) if (invc[i]^invr[i]) a[i][i]^=1;
        REP(i,0,n)
            REP(j,i,n) swap(a[i][j],a[j][i]);
//        REP(i,0,n){
//            REP(j,0,n) printf("%d",a[i][j]);ENDL;
//        }
//        ENDL;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    REP(i,0,n) {
        scanf("\n%s",s);
        REP(j,0,n) a[i][j]=s[j]-'0';
    }
    cout<<solve();
}