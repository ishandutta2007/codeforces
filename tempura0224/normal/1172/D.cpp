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
    int r[n],c[n];
    int pr[n],pc[n];
    rep(i,n){
        cin>>r[i];
        --r[i];
        pr[r[i]]=i;
    }
    rep(i,n){
        cin>>c[i];
        --c[i];
        pc[c[i]]=i;
    }
    vector<pair<int,int>> ans1,ans2;
    rep(i,n){
        if(pr[i]==i&&pc[i]==i)continue;
        int ri = pr[i];
        int ci = pc[i];
        int nr = r[i];
        int nc = c[i];
        ans1.emplace_back(i+1,ci+1);
        ans2.emplace_back(ri+1,i+1);
        if(ri!=i){
            swap(pr[i],pr[nr]);
            swap(r[i],r[ri]);
        }
        if(ci!=i){
            swap(pc[i],pc[nc]);
            swap(c[i],c[ci]);
        }
    }
    int m=ans1.size();
    cout<<m<<endl;
    rep(i,m){
        cout<<ans1[i].first<<" "<<ans1[i].second<<" "<<ans2[i].first<<" "<<ans2[i].second<<endl;
    }
    return 0;
}