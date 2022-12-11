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

int n,x,ans[N],h[N];
vector <int> a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&x);
        a[x].push_back(i);
    }
    int top=1;
    FORD(i,N-1,1){
        int m=a[i].size();
        REP(j,0,m) ans[a[i][j]]=top;
        top+=m;
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}