#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("628.inp","r",stdin)
#define OUTPUT freopen("628.out","w",stdout)
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
const int N=3e5+10;

int n,k;
string s;
string solve(){
    int kmax=0;
    for(auto ch:s) kmax+=max(ch-'a','z'-ch);
    if (kmax<k) return "-1";
    REP(i,0,n){
        int re=max(s[i]-'a','z'-s[i]);
        int v=min(re,k);
        k-=v;
        if (s[i]+v<='z') s[i]+=v;
        else if (s[i]-v>='a') s[i]-=v;
    }
    return s;
}
int main(){
    cin>>n>>k>>s;
    cout<<solve();
}