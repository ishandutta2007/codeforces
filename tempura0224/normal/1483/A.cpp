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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> ok(k);
    vector<int> cnt(n);
    rep(i,k){
        int m;
        cin>>m;
        rep(j,m){
            int x;
            cin>>x;
            ok[i].push_back(x-1);
        }
    }
    vector<int> ans(k);
    rep(i,k){
        if(ok[i].size()==0){
            cout<<"NO"<<endl;
            return;
        }
        ans[i]=ok[i][0];
        ++cnt[ok[i][0]];
    }
    int ma = (k+1)/2;
    rep(i,n){
        if(cnt[i]>ma){
            rep(j,k){
                if(ok[j].size()>1&&ok[j][0]==i&&cnt[i]>ma){
                    --cnt[i];
                    ans[j]=ok[j][1];
                }
            }
            if(cnt[i]>ma){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    rep(i,k)cout<<ans[i]+1<<" \n"[i+1==k];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}