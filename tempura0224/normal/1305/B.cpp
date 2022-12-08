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
    string s;
    cin>>s;
    int n=s.size();
    bool l = 0, r = 0;
    rep(i,n){
        if(s[i]=='(')l=1;
        if(s[i]==')'&& l)r=1;
    }
    if(r==0){
        cout<<0<<endl;
        return 0;
    }
    vector<int> cl(n+1),cr(n+1);
    rep(i,n)cl[i+1]=s[i]=='(';
    rep(i,n)cr[i]=s[i]==')';
    rep(i,n)cl[i+1]+=cl[i];
    rep(i,n)cr[n-i-1]+=cr[n-i];
    rep(i,n+1){
        if(cl[i]==cr[i]){
            cout<<1<<endl;
            cout<<cl[i]+cr[i]<<endl;
            rep(j,i){
                if(s[j]=='(')cout<<j+1<<" ";
            }
            REP(j,i,n){
                if(s[j]==')')cout<<j+1<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    return 0;
}