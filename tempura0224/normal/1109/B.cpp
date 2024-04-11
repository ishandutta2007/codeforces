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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.size();
    bool ok=false;
    rep(i,n){
        if(n%2 && i == n/2)continue;
        if(s[i]!=s[0])ok=true;
    }
    if(!ok){
        cout<<"Impossible"<<endl;
        return 0;
    }
    REP(i,1,n){
        string t = s.substr(i)+s.substr(0,i);
        if(t==s)continue;
        bool pari = true;
        rep(j,n)if(t[j]!=t[n-j-1])pari=false;
        if(pari){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<2<<endl;
    return 0;
}