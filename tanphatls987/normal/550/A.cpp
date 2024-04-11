#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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

string s;
int h[N];
string solve(){
    int n=s.length();
    FOR(i,1,n-1) if (s[i-1]=='A'&&s[i]=='B') h[i]=1;
    FOR(i,1,n) h[i]+=h[i-1];
    FOR(i,1,n-1) if (s[i-1]=='B'&&s[i]=='A'&&h[n]-(h[i+1]-h[max(i-2,0)])) return "YES";
    return "NO";
}
int main(){
    cin>>s;
    cout<<solve();
}