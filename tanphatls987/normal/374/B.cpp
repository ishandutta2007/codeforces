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
const int N=1e5+10;

string s;
ll f[N][2];
int g[N];
int main(){
    cin>>s;
    int n=s.length();
    FOR(i,2,n) g[i]=max(g[i-1],g[i-2]+(s[i-1]-'0'+s[i-2]=='9'));
    f[0][0]=1;
    FOR(i,1,n){
        FOR(j,0,1){
            int low=g[i]-(g[i-1]-j);
            if (low<=1) f[i][low]+=f[i-1][j];
        }
        if (i>1&&s[i-1]-'0'+s[i-2]=='9'){
            FOR(j,0,1){
                int low=g[i]-(g[i-2]-j+1);
                if (low<=1) f[i][low]+=f[i-2][j];
            }
        }
    }
    //FOR(i,1,n) printf("%lld %lld\n",f[i][0],f[i][1]);
    cout<<f[n][0];
}