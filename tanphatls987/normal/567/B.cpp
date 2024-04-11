#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=1e6+10,M=1e2+10;

int h[N],ans[M];
int main(){
    int n,x;
    char ch;
    cin>>n;
    FOR(i,1,n){
        cin>>ch>>x;
        if (ch=='+') ans[i]++;
        else {
            if (!h[x]) ans[0]++,h[x]=1;
            ans[i+1]--;
        }
        h[x]^=1;
    }
//    FOR(i,1,n) cout<<ans[i]<<" \n"[i==n];
    FOR(i,1,n) ans[i]+=ans[i-1];
    cout<<*max_element(ans,ans+n+1);
}