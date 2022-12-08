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
    int t;cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int ma = n*(n-1)/2;
        int mi = 0;
        REP(i,2,n+1){
            int c = i;
            while(c>1){
                c/=2;
                mi++;
            }
        }
        if(d<mi||d>ma){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        vector<vector<int>> depth(n);
        rep(i,n)depth[i].push_back(i);
        int b = n-1;
        while(ma>d){
            while(depth[b].empty())--b;
            int x = depth[b].back();
            depth[b].pop_back();
            int to = b;
            while(to>1 && ma>d){
                --ma;
                --to;
            }
            while(depth[to].size()>=2*depth[to-1].size()){
                ++to;
                ++ma;
            }
            depth[to].push_back(x);
        }
        vector<int> x(n);
        int j=0;
        rep(i,n){
            for(auto e:depth[i])x[j++]=i;
            depth[i].clear();
        }
        vector<int> y(n);
        rep(i,n){
            y[i]=depth[x[i]].size();
            depth[x[i]].push_back(i+1);
        }
        rep(i,n-1){
            cout<<depth[x[i+1]-1][y[i+1]/2]<<" ";
        }
        cout<<endl;
    }
    return 0;
}