#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=0;

string s1,s2;
int h[2][26][2]={0};
void solve(){
    for(auto c:s1) if (c>='a'&&c<='z')
        h[0][c-'a'][0]++;else h[0][c-'A'][1]++;
    for(auto c:s2) if (c>='a'&&c<='z')
        h[1][c-'a'][0]++;else h[1][c-'A'][1]++;
    int ans0=0,ans1=0;
    FOR(i,0,25)
        FOR(j,0,1){
            int v=min(h[0][i][j],h[1][i][j]);
            ans0+=v;
            h[0][i][j]-=v;h[1][i][j]-=v;
        }
    FOR(i,0,25)
        FOR(j,0,1) ans1+=min(h[0][i][j],h[1][i][1-j]);
    cout<<ans0<<" "<<ans1;
}
int main(){
    cin>>s1>>s2;
    solve();
}