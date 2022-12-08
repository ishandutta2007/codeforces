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
    int cnt=0;
    vector<int> ans;
    rep(i,20){
        int idx=0;
        while((1<<idx)<n)++idx;
        --idx;
        while(idx>=0&&(1<<idx)&n)--idx;
        if(idx==-1)break;
        ++cnt;
        ans.push_back(idx+1);
        int res=(1<<(idx+1))-1;
        n^=res;
        idx=0;
        while((1<<idx)<n)++idx;
        --idx;
        while(idx>=0&&(1<<idx)&n)--idx;
        if(idx==-1)break;
        ++cnt;
        ++n;
    }
    cout<<cnt<<endl;
    for(auto e : ans){
        cout<<e<<" ";
    }
    return 0;
}