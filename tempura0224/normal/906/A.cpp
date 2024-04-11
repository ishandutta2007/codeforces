#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    set<char> st;
    rep(i,26)st.insert('a'+i);
    bool ok=false;
    int ans=0;
    rep(i,n-1){
        char c;string s;
        cin>>c>>s;
        if(c=='.'){
            for(auto& t:s)st.erase(t);
        }
        else if(c=='!'){
            vector<int> used(26);
            for(auto& t:s)used[t-'a']=1;
            rep(i,26){
                if(!used[i])st.erase('a'+i);
            }
            if(ok)++ans;
        }
        else {
            if(ok)++ans;
            st.erase(s[0]);
        }
        if(st.size()==1)ok=true;
    } 
    cout<<ans<<endl;
    return 0;
}