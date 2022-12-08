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
    int n,k;
    cin>>n>>k;
    set<pair<int,int>>st1,st2;
    rep(i,n){
        int x;
        cin>>x;
        st1.emplace(i,x);
        st2.emplace(x,i);
    }
    string ans("1",n);
    st1.emplace(inf,inf);
    int cur=0;
    while(!st2.empty()){
        auto p=*prev(st2.end());
        int X=p.first,I=p.second;
        auto itr=st1.lower_bound({I,X});
        rep(i,k){
            if(itr==st1.begin())break;
            --itr;
        }
        rep(i,k+1){
            st2.erase({itr->second,itr->first});
            ans[itr->first]=cur+'1';
            itr=st1.erase(itr);
            if(itr->first>I)break;
        }
        rep(i,k){
            if(itr->first==inf)break;
            st2.erase({itr->second,itr->first});
            ans[itr->first]=cur+'1';
            itr=st1.erase(itr);
        }
        cur=(cur+1)%2;
    }
    cout<<ans<<endl;
    return 0;
}