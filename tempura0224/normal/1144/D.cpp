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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    int a[n];
    rep(i,n){
        cin>>a[i];
        ++mp[a[i]];
    }
    int ans=0;
    int ret=0;
    for(auto p : mp){
        if(p.second>ans)ret=p.first;
        ans=max(ans,p.second);
    }
    ans=n-ans;
    int ok=-1;
    int st=0;
    vector<pair<int,int>> query1,query2;
    while(1){
        while(st<n&&a[st]!=ret)++st;
        if(st==n)break;
        for(int i = st-1;i>ok;--i){
            if(a[i]<ret)query1.push_back({1,i+1});
            else query1.push_back({2,i+1});
        }
        ok=st;
        ++st;
    } 
    REP(i,ok,n-1){
        if(a[i+1]<ret)query2.push_back({1,i+2});
        else query2.push_back({2,i+2});
    }
    cout<<ans<<endl;
    for(auto p : query1){
        cout<<p.first<<" "<<p.second<<" "<<p.second+1<<endl;
    }
    for(auto p : query2){
        cout<<p.first<<" "<<p.second<<" "<<p.second-1<<endl;
    }
    return 0;
}