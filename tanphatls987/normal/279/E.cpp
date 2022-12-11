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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,f[N][2];
string s;
int main(){
    cin>>s;
    int n=s.length();
    f[0][1]=1;
    FOR(i,1,n){
        if (s[i-1]=='1'){
            f[i][1]=f[i-1][1];
            f[i][0]=min(f[i-1][1],f[i-1][0])+1;
        }else{
            f[i][0]=min(f[i-1][1]+1,f[i-1][0]);
            f[i][1]=min(f[i-1][1]+1,f[i-1][0]+1);
        }
    }
    cout<<f[n][0];
}