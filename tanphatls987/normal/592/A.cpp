#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("cf.inp","r",stdin)
#define OUTPUT freopen("cf.out","w",stdout)
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
const int N=0;

string s[10];
void prepare(){
    FOR(i,1,8) cin>>s[i];
}
char solve(){
    int ans1=inf,ans2=inf;
    FOR(col,0,7){
        bool block=0;
        FOR(i,1,8) if (s[i][col]=='B') block=1;
        else if (s[i][col]=='W'&&!block) ans1=min(ans1,i-1);
    }
    FOR(col,0,7){
        bool block=0;
        FORD(i,8,1) if (s[i][col]=='W') block=1;
        else if (s[i][col]=='B'&&!block) ans2=min(ans2,8-i);
    }
    if (ans1<=ans2) return 'A';
    return 'B';
}
int main(){
    prepare();
    cout<<solve();
}