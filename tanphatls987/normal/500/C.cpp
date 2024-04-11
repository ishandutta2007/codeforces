#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=5e2+10;

int w[N],p[1005],n,m,h[N]={0},s[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",w+i);
    FOR(i,1,m) scanf("%d",p+i);
}
void solve(){
    int top=0,ans=0;
    FOR(i,1,m){
        if (!h[p[i]]){
            s[++top]=p[i];
            h[p[i]]=top;
        }
        FORD(j,h[p[i]],2){
            ans+=w[s[j-1]];
            h[s[j-1]]=j;
            s[j]=s[j-1];
        }
        s[1]=p[i];
        h[p[i]]=1;
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}