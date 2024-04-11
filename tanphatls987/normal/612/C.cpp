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
const int N=1e6+10;
const int dict[8]={'(','[','{','<','>','}',']',')'};

int n;
string s;
stack <int> st;
void prepare(){
    cin>>s;
    n=s.length();
}
int cv(char ch){
    int ans=0;
    while (dict[ans]!=ch) ans++;
    return ans;
}
void solve(){
    int ans=0;
    REP(i,0,n){
        int v=cv(s[i]);
        if (v<4) st.push(v);
        else{
            if (st.empty()){
                printf("Impossible");
                return;
            }
            int v1=st.top();st.pop();
            ans+=(v+v1)!=7;
        }
    }
    if (!st.empty()){
        printf("Impossible");
        return;
    }
    cout<<ans;
}
int main(){
    prepare();
    solve();
}