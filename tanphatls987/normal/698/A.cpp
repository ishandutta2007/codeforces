#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,a[N];
int f[N][3];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
int solve(){
    FOR(i,1,n){
        f[i][0]=*max_element(f[i-1],f[i-1]+3);
        if (a[i]&1)
            f[i][1]=max(f[i-1][0],f[i-1][2])+1;
        if (a[i]&2)
            f[i][2]=max(f[i-1][0],f[i-1][1])+1;
    }
    return n-*max_element(f[n],f[n]+3);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}