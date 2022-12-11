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
const int N=0;

string s,ans;
bool failed(int n){
    if (n>=3&&ans[n-1]==ans[n-2]&&ans[n-2]==ans[n-3]) return 1;
    if (n>=4&&ans[n-1]==ans[n-2]&&ans[n-3]==ans[n-4]) return 1;
    return 0;
}
int main(){
    cin>>s;
    int n=0;
    for(auto c:s){
        ans.push_back(c);
        if (failed(++n)) ans.pop_back(),n--;
    }
    cout<<ans;
}