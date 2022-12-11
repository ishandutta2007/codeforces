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
const int N=5e4+10;

set <string> se;
int n,h[N][2];
string s;
void prepare(){
    cin>>s;
    n=s.length();
    s=s+"@@@";
}
void BFS(){
    h[n][0]=h[n][1]=1;
    FORD(i,n,1){
        if (i<n){
            FOR(j,0,1) if (h[i][j]) se.insert(s.substr(i,j+2));
        }
        FOR(use,0,1) if (i-use-2>4){
            if (h[i][use^1]) h[i-use-2][use]=1;
            if (h[i][use]&&s.substr(i-use-2,use+2)!=s.substr(i,use+2)) h[i-use-2][use]=1;
        }
//        cout<<h[i][0]<<" "<<h[i][1]<<'\n';
    }
    cout<<se.size()<<'\n';
    for(auto i:se) cout<<i<<'\n';
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    BFS();
}