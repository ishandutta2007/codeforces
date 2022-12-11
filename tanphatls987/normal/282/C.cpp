#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

string s1,s2;
string solve(){
    int n=s1.length(),m=s2.length();
    if (n!=m) return "NO";
    int b1=count(s1.begin(),s1.end(),'1'),b2=count(s2.begin(),s2.end(),'1');
    if ((b1>0)!=(b2>0)) return "NO";
    return "YES";
}
int main(){
    cin>>s1>>s2;
    cout<<solve();
}