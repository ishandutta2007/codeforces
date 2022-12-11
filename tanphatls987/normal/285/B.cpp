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
const int N=1e5+10;

int n,st,en,p[N],h[N];
void prepare(){
    scanf("%d%d%d",&n,&st,&en);
    FOR(i,1,n) scanf("%d",p+i);
}
int solve(){
    int ans=0;
    while (st!=en){
        if (h[st]) return -1;
        h[st]=1;
        st=p[st];
        ans++;
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}