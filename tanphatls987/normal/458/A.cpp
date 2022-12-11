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

const ll inf=1e16;
const int MOD=1e9+7;
const int N=1e5+10;

int h[2][N];
string s[2];
char solve(){
    FORD(i,N-1,0){
        if (h[0][i]&&!h[1][i]) return '>';
        if (h[1][i]&&!h[0][i]) return '<';
    }
    return '=';
}
int main(){
    cin>>s[0]>>s[1];
    FOR(sel,0,1){
        int n=s[sel].length();
        FOR(i,1,n) h[sel][i]=s[sel][n-i]-'0';
        FOR(i,1,n) if (h[sel][i]){
            int st=i;
            while (h[sel][i+1]) i++;
            for(int j=i;j>=st;j-=2) if (h[sel][j]&&h[sel][j-1]) {
                h[sel][j+1]=1;
                h[sel][j]=h[sel][j-1]=0;
            }
        }
    }
    cout<<solve();
}