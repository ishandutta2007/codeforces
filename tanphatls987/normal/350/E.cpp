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
const int N=3e2+10;

int n,m,k,a[N],h[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,k) {
        scanf("%d",a+i);
        h[a[i]]=1;
    }
}
int iden(int x){
    if (x==n) return a[1];
    if (x==a[1]) return n;
    return x;
}
void solve(){
    int maxe=(n-1)*(n-2)/2+(n-k);
    if (k==n||m>maxe){
        printf("-1");
        return;
    }
    FOR(i,1,n-2) printf("%d %d\n",iden(i),iden(i+1));
    m-=n-2;
    FOR(i,1,n-1) if (m&&!h[iden(i)]){
        printf("%d %d\n",iden(n),iden(i));
        m--;
    }
    FOR(i,1,n-2)
        FOR(j,i+2,n-1) if (m){
            printf("%d %d\n",iden(i),iden(j));
            m--;
        }
}
int main(){
    prepare();
    solve();
}