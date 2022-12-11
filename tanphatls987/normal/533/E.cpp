#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
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

int n;
string s1,s2;
int solve(){
    int dif=0;
    REP(i,0,n) dif+=s1[i]!=s2[i];
    if (dif==1) return 2;
    int ans=0;
    FOR(j,0,1){
        int L=0;
        while (s1[L]==s2[L]) L++;
        int R=L+1;
        while (R<n&&s1[R-1]==s2[R]) R++;
    //cout<<L<<" "<<R<<'\n';
        while (R<n&&s1[R]==s2[R]) R++;
        ans+=(R==n);
        swap(s1,s2);
    }
    return ans;
}
int main(){
    cin>>n>>s1>>s2;
    cout<<solve();
}