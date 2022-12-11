#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("625.inp","r",stdin)
#define OUTPUT freopen("625.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int f[N];
string s1,s2;
int solve(){
    int n=s1.length(),m=s2.length();
    FOR(i,m,n) if (s1.substr(i-m,m)==s2) f[i]=f[i-m]+1;
    else f[i]=f[i-1];
    return f[n];
}
int main(){
    cin>>s1>>s2;
    cout<<solve();
}