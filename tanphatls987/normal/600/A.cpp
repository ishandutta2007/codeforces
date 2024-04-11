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

string s;
void solve(){
    string ans[2];
    s=s+',';
    int n=s.length();
    for(int en=0;en<n;en++){
        bool ok=0;
        int st=en;
        while (s[en]!=','&&s[en]!=';'){
//            cout<<en<<" "<<s[en]<<'\n';
            if ((s[en]<'0'||s[en]>'9')) ok=1;
            en++;
        }
        int len=en-st;
        if (!len) ok=1;
        if (len>1&&!ok&&s[st]=='0') ok=1;
        ans[ok]=ans[ok]+','+s.substr(st,en-st);
    }
    FOR(i,0,1){
        if (ans[i].empty()) {
            cout<<"-\n";
            continue;
        }
        ans[i][0]='"';
        ans[i].push_back('"');
        cout<<ans[i]<<'\n';
    }
}

int main(){
    cin>>s;
    solve();
}