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

int f[N][4];
string s;
int main(){
    cin>>s;
    int n=s.length();
    f[0][0]=1;
    int cur=0;
    ll ans=0;
    REP(i,0,n){
        FOR(j,0,3) f[i+1][j*10%4]+=f[i][j];
        cur=(cur*10+s[i]-'0')%4;
        ans+=f[i+1][cur];
        f[i+1][cur]++;
    }
    cout<<ans;
}