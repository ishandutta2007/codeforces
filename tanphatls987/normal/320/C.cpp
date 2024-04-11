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
const int N=1e2+10;

int p2[N];
string s;
int main(){
    cin>>s;
    int n=s.length();
    p2[0]=1;
    FOR(i,1,n) p2[i]=(p2[i-1]*2)%MOD;
    int ans=0;
    REP(i,0,n) if (s[i]=='1') ans=(ans+1LL*p2[i]*p2[n-i-1]%MOD*p2[n-i-1])%MOD;
    cout<<ans;
}