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
const int N=1e5+10;

int n,k,a[N],g[N];
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(en,1,n){
        int st=en;
        while (en<n&&a[en+1]==a[st]) en++;
        g[a[st]]+=(st>1)+(en<n);
        if (st>1&&en<n&&a[st-1]!=a[en+1]) g[a[st]]--;
//        printf("%d %d %d\n",st,a[st],g[a[st]]);
    }
//    FOR(i,1,k) cout<<g[i]<<" \n"[i==k];
    cout<<max_element(g+1,g+k+1)-g;
}