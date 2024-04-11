#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=5e3+10;

int n,a[N],t[N][N],nex[N];
map <int,int> ma;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FORD(i,n,1){
        nex[i]=ma[a[i]]?ma[a[i]]:n+1;
        ma[a[i]]=i;
    }
//    FOR(i,1,n) cout<<nex[i]<<" \n"[i==n];
    FOR(i,1,n){
        t[i][i]=i;
        FOR(j,i+1,n) t[i][j]=(a[j]<a[t[i][j-1]])?j:t[i][j-1];
    }
}
int DP(int L,int R){
//    printf("%d %d\n",L,R);
    if (R<L) return 0;
    int ans=a[t[L][R]]-max(a[L-1],a[R+1]);
    for(int x=L,y=t[L][R];x<=R;x=y+1,y=nex[y]){
        ans+=DP(x,min(y-1,R));
        if (ans>R-L+1) break;
    }
    ans=min(ans,R-L+1);
//    printf("%d %d %d\n",L,R,ans);
    return ans;
}
int main(){
    prepare();
    cout<<DP(1,n);
}