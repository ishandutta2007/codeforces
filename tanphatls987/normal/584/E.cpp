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

int n,a[N],b[N];
vector <ii> mswap;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) {
        int x;
        scanf("%d",&x);
        b[x]=i;
    }
//    FOR(i,1,n) cout<<b[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
}
void solve(){
    int ans=0;
    while (1){
        bool ok=1;
        FOR(i,1,n) if (b[a[i]]!=i) ok=0;
        if (ok) break;
        FOR(i,1,n) if (b[a[i]]<i){
            int pos=i,x=a[i];
        //        printf("%d\n",i);
            FORD(j,i-1,b[x]) if (b[a[j]]>=pos){
                ans+=pos-j;
                mswap.push_back(ii(j,pos));
                swap(a[j],a[pos]);
                pos=j;
            }
        }
    }
    printf("%d\n%d\n",ans,int(mswap.size()));
    for(auto i:mswap) printf("%d %d\n",i.X,i.Y);
}
int main(){
    prepare();
    solve();
}