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
    if(n%2){
        cout<<"No"<<endl;
        return 0;
    }
    string s;
    cin>>s;
    int cnt = 0;
    rep(i,n)cnt+=(s[i]=='(');
    if(2*cnt!=n){
        cout<<"No"<<endl;
        return 0;
    }
    int mi = 0;
    int sum = 0;
    rep(i,n){
        if(s[i]=='(')++sum;
        else mi = min(mi,--sum);
    }
    if(mi>=-1){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}