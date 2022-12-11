#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("107.inp","r",stdin)
#define OUTPUT freopen("107.out","w",stdout)
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
const int N=4e6+10;

ll n;
int t[N];
void solve(){
    vector <int> ans;
    REP(i,2,N) if (!t[i])
        for(int j=i+i;j<N;j+=i) t[j]=1;
    FOR(i,2,min(int(sqrt(n)),N-1)) if (!t[i]&&n%i==0) ans.push_back(i);
    if (ans.size()>1){
        ll tmp=1LL*ans[0]*ans[1];
        if (tmp<n){
            printf("1\n");
            cout<<tmp;
            return;
        }
    }
    if (ans.empty()){
        printf("1\n0");
        return;
    }
    for(auto i:ans){
        ll tmp=1LL*i*i;
        if (tmp<n&&n%tmp==0){
            printf("1\n%I64d",tmp);
            return;
        }
    }
    printf("2");
}
int main(){
    cin>>n;
    solve();
}