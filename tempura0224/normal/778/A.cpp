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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int ok=0, ng=n;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        int cur=0;
        vector<int> b(n,1);
        rep(i,mid)b[a[i]-1]=false;
        rep(i,n){
            if(!b[i])continue;
            if(s[i]==t[cur])++cur;
            if(cur==t.size())break;
        }
        (cur==t.size()?ok:ng)=mid;
    }
    cout<<ok<<endl;
    return 0;
}