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

int a[3][2];
string ch="ABC";
void solve(){
    int S=0;
    FOR(i,0,3) S+=a[i][0]*a[i][1];
    int n=int(sqrt(S));
    if (n*n==S){
        bool ok=1;
        FOR(i,0,2) if (max(a[i][0],a[i][1])<n) ok=0;
        if (ok){
            printf("%d\n",n);
            FOR(i,0,2)
                FOR(j,1,min(a[i][0],a[i][1])){
                    FOR(k,1,n) printf("%c",'A'+i);
                    ENDL;
                }
            return;
        }
        FOR(i,0,2) if (a[i][0]<n&&a[i][1]<n) {
            swap(a[i][0],a[2][0]);
            swap(a[i][1],a[2][1]);
            swap(ch[i],ch[2]);
        }
        FOR(p0,0,1){
            FOR(p1,0,1){
                FOR(t,0,1){
                    if (a[2][0]+a[t][0]==n&&a[2][1]+a[t^1][1]==n){
                        if (a[2][0]==a[t^1][0]){
                            printf("%d\n",n);
                            FOR(i,1,n){
                                FOR(j,1,n) printf("%c",i<=a[2][0]?(j<=a[2][1]?ch[2]:ch[t^1]):ch[t]);
                                ENDL;
                            }
                            return;
                        }
                        if (a[2][1]==a[t][1]){
                            printf("%d\n",n);
                            FOR(i,1,n){
                                FOR(j,1,n) printf("%c",j<=a[2][1]?(i<=a[2][0]?ch[2]:ch[t]):ch[t^1]);
                                ENDL;
                            }
                            return;
                        }
                    }
                }
                swap(a[0][0],a[0][1]);
            }
            swap(a[1][0],a[1][1]);
        }
    }
    printf("-1");
}
int main(){
    FOR(i,0,2)
        FOR(j,0,1) cin>>a[i][j];
    solve();
}