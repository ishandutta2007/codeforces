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
    int x[n],y[n];
    rep(i,n)cin>>x[i]>>y[i];
    vector<int>ans;
    while(1){
        int cnt = 0;
        rep(i,n){
            if((x[i]-y[i])%2==0){
                cnt++;
                ans.push_back(i+1);
            }
        }
        if(cnt!=0 && cnt!=n)break;
        ans.clear();
        if(cnt == 0){
            rep(i,n){
                if(x[i]%2==0){
                    ++cnt;
                    ans.push_back(i+1);
                }
            }
            if(cnt!=0 && cnt!=n)break;
            ans.clear();
            rep(i,n){
                if(x[i]%2!=0)--x[i];
                x[i]/=2;
                if(y[i]%2!=0)--y[i];
                y[i]/=2;
            }
        }
        else {
            cnt = 0;
            rep(i,n){
                if(x[i]%2==0){
                    ++cnt;
                    ans.push_back(i+1);
                }
            }
            if(cnt!=0 && cnt!=n)break;
            ans.clear();
            rep(i,n){
                if(x[i]%2!=0)--x[i];
                x[i]/=2;
                if(y[i]%2!=0)--y[i];
                y[i]/=2;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto e:ans)cout<<e<<" ";
    cout<<endl;
    return 0;
}