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
const int N=0;

int n,p,q;
string s;
void solve(){
    for(int i=0;i<=n;i+=p) if ((n-i)%q==0){
        cout<<i/p+(n-i)/q<<'\n';
        REP(j,0,i) {
            printf("%c",s[j]);
            if (j%p==p-1) ENDL;
        }
        REP(j,i,n){
            printf("%c",s[j]);
            if ((j-i)%q==q-1) ENDL;
        }
        return;
    }
    printf("-1");
}

int main(){
    cin>>n>>p>>q;
    cin>>s;
    solve();

}