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
const int N=1e5+10;

int n,m,tmp,w[N];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d",&tmp,w+i);
    sort(w+1,w+m+1,greater<int>());
    int L=1,R=n;
    while (L<=R){
        int M=(L+R)/2;
        ll use=1LL*M*(M-1)/2;
        if (M%2==0) use+=M/2-1;
        if (use<n) L=M+1;
        else R=M-1;
    }
    ll ans=0;
    FOR(i,1,min(R,m)) ans+=w[i];
    cout<<ans;
}