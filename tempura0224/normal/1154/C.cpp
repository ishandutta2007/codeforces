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
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> ans(7,longinf);
    ll aa=a/3*7;
    if(a%3==0){
        ans[0]=min(ans[0],aa);
        ans[1]=min(ans[1],aa+2);
        ans[2]=min(ans[2],aa+1);
        ans[3]=min(ans[3],aa);
        ans[4]=min(ans[4],aa+2);
        ans[5]=min(ans[5],aa+1);
        ans[6]=min(ans[6],aa);
    }
    else if(a%3==1){
        ans[0]=min(ans[0],aa+3);
        ans[1]=min(ans[1],aa+5);
        ans[2]=min(ans[2],aa+4);
        ans[3]=min(ans[3],aa+3);
        ans[4]=min(ans[4],aa+3);
        ans[5]=min(ans[5],aa+2);
        ans[6]=min(ans[6],aa+1);
    }
    else if(a%3==2){
        ans[0]=min(ans[0],aa+6);
        ans[1]=min(ans[1],aa+6);
        ans[2]=min(ans[2],aa+5);
        ans[3]=min(ans[3],aa+4);
        ans[4]=min(ans[4],aa+6);
        ans[5]=min(ans[5],aa+5);
        ans[6]=min(ans[6],aa+4);
    }
    ll bb=b/2*7;
    if(b%2==0){
        ans[0]=min(ans[0],bb+1);
        ans[1]=min(ans[1],bb);
        ans[2]=min(ans[2],bb+3);
        ans[3]=min(ans[3],bb+2);
        ans[4]=min(ans[4],bb+1);
        ans[5]=min(ans[5],bb);
        ans[6]=min(ans[6],bb+2);
    }
    else if(b%2==1){
        ans[0]=min(ans[0],bb+5);
        ans[1]=min(ans[1],bb+4);
        ans[2]=min(ans[2],bb+6);
        ans[3]=min(ans[3],bb+5);
        ans[4]=min(ans[4],bb+4);
        ans[5]=min(ans[5],bb+3);
        ans[6]=min(ans[6],bb+6);
    }
    ll cc=c/2*7;
    if(c%2==0){
        ans[0]=min(ans[0],cc+2);
        ans[1]=min(ans[1],cc+1);
        ans[2]=min(ans[2],cc);
        ans[3]=min(ans[3],cc+1);
        ans[4]=min(ans[4],cc);
        ans[5]=min(ans[5],cc+4);
        ans[6]=min(ans[6],cc+3);
    }
    else if(c%2==1){
        ans[0]=min(ans[0],cc+4);
        ans[1]=min(ans[1],cc+3);
        ans[2]=min(ans[2],cc+2);
        ans[3]=min(ans[3],cc+6);
        ans[4]=min(ans[4],cc+5);
        ans[5]=min(ans[5],cc+6);
        ans[6]=min(ans[6],cc+5);
    }
    cout<<*max_element(ans.begin(), ans.end())<<endl;
    return 0;
}