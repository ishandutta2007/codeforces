#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=1e3+10,M=1e6+10;

vector <int> v[N];
int n,ans[M];
void prepare(){
    int x;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%*d",&x);
        v[x].push_back(i);
    }
}
void solve(){
    int diff=0;
    FOR(i,1,1000)
        for(auto idx:v[i]) if (diff+i<=500) diff+=i;
        else diff-=1000-i,ans[idx]=1;
    FOR(i,1,n) printf("%c",ans[i]?'G':'A');
}
int main(){
    prepare();
    solve();
}