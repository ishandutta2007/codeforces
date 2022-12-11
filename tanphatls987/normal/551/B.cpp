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
const int N=30;

string s,s1,s2;
int h[30],g[2][30];
void solve(){
    int u1=0,u2=0;
    FOR(i,0,100000){
        int cu2=inf;
        FOR(j,0,25){
            ll cur=h[j]-1LL*g[0][j]*i;
            if (cur<0) cu2=-inf;
            if (g[1][j]) cu2=min(cu2,int(cur/g[1][j]));
        }
        if (cu2+i>u1+u2) u1=i,u2=cu2;
    }
    FOR(i,0,25) h[i]-=u1*g[0][i]+u2*g[1][i];
    FOR(i,1,u1) cout<<s1;
    FOR(i,1,u2) cout<<s2;
    FOR(i,0,25)
        FOR(j,1,h[i]) cout<<char(i+'a');
}
int main(){
    cin>>s;
    for(auto c:s) h[c-'a']++;
    cin>>s1;
    for(auto c:s1) g[0][c-'a']++;
    cin>>s2;
    for(auto c:s2) g[1][c-'a']++;
    solve();
}