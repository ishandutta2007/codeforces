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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n);
        rep(i,m){
            int x,y;
            cin>>x>>y;
            --x;--y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> c(n);
        c[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(auto to:v[x]){
                if(c[to]==0){
                    c[to]=-c[x];
                    q.push(to);
                }
            }
        }
        int x=0,y=0;
        rep(i,n){
            if(c[i]==1)++x;
            else ++y;
        }
        if(x<y){
            cout<<x<<endl;
            rep(i,n){
                if(c[i]==1)cout<<i+1<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<y<<endl;
            rep(i,n){
                if(c[i]==-1)cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}