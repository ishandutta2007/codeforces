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
    int ans=1;
    map<int,int>mp;
    vector<int> cnt(101010);
    rep(i,n){
        int x;cin>>x;
        if(cnt[x]!=0){
            --mp[cnt[x]];
            if(mp[cnt[x]]==0)mp.erase(cnt[x]);
        }
        ++cnt[x];
        mp[cnt[x]]++;
        if(mp.size()==2){
            int a[2], b[2];
            int j=0;
            for(auto e:mp){
                a[j]=e.first, b[j]=e.second;
                ++j;
            }
            if(a[0]+1==a[1]&&b[1]==1)ans=i+1;
            if(a[0]==1&&b[0]==1)ans=i+1;
        }
        if(mp.size()==1 && mp.begin()->first==1)ans=i+1;
        if(mp.size()==1 && mp.begin()->second==1)ans=i+1;
    }
    cout<<ans<<endl;
    return 0;
}