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
const int N=0;

string s,t;
int solve(){
    int n=s.length(),m=t.length();
    int L=-1,c=0;
    while (c<n){
        if ((L++)>=m) return 0;
        if (t[L]==s[c]) c++;
    }
    int R=m;c=n-1;
    while (c>=0){
        R--;
        if (t[R]==s[c]) c--;
    }
    return max(0,R-L);
}
int main(){
    cin>>s>>t;
    cout<<solve();
}