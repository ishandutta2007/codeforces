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
    string s;
    cin>>s;
    vector<int> a(10);
    rep(i,n){
        if(s[i]=='L'){
            int idx = 0;
            while(a[idx])++idx;
            a[idx]=1;
        }
        else if(s[i]=='R'){
            int idx = 9;
            while(a[idx])--idx;
            a[idx]=1;
        }
        else {
            a[s[i]-'0']=0;
        }
    }
    rep(i,10)cout<<a[i];
    cout<<endl;
    return 0;
}