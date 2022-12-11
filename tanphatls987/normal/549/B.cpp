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

char s[N][N];
int n,h[N],a[N];
int main(){
    scanf("%d",&n);
    REP(i,0,n) scanf("\n%s",s[i]);
    REP(i,0,n) scanf("%d",a+i);
    vector <int> ans;
    while (1){
        bool ok=1;
        REP(i,0,n) if (h[i]==a[i]){
            ans.push_back(i+1);
            REP(j,0,n) if (s[i][j]=='1') h[j]++;
            ok=0;
        }
//        REP(i,0,n) printf("%d ",h[i]);ENDL;
        if (ok) break;
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}