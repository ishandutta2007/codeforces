#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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
const int N=0;
const int md[12]={31,29,31,30,31,30,31,31,30,31,30,31};
const int st=4;

int x;
string s1,s2;
int solve(){
    int ans=0;
    if (s2[0]=='w'){
        x--;
        REP(i,0,366) if ((i+st)%7==x) ans++;
        return ans;
    }
    REP(i,0,12) if (x<=md[i]) ans++;
    return ans;
}
int main(){
    cin>>x>>s1>>s2;
    cout<<solve();
}