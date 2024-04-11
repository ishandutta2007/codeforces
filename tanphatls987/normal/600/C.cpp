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
const int alp=26;

int h[alp],s[alp];
string st;

void prepare(){
    cin>>st;
    for(auto i:st) h[i-'a']++;
}
string solve(){
    int top=0,n=st.length();
    REP(i,0,alp) if (h[i]&1) s[++top]=i;
    string ans;
    REP(i,0,top/2) h[s[top-i]]--,h[s[i+1]]++;
    if (top&1) h[s[top/2+1]]--;
    REP(i,0,alp)
        FOR(j,1,h[i]/2) ans.push_back('a'+i);
    if (top&1) ans.push_back(s[top/2+1]+'a');
    FORD(len,n/2-1,0) ans.push_back(ans[len]);
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}