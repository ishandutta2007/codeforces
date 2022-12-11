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
const int N=1e6+100;

int h[N];
void prepare(){
    int n,x;
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        h[x]++;
    }
}
int solve(){
    REP(i,0,N-1) h[i+1]+=h[i]>>1,h[i]%=2;
    return count(h,h+N,1);
}
int main(){
    prepare();
    cout<<solve();
}