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
    int n, a, b;
    cin >> n >> a >> b;
    if(a!=1&&b!=1){
        cout<<"NO"<<endl;
    }
    else if(a==1 && b==1){
        if(n==2||n==3){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
            rep(i,n){
                rep(j,n)cout<<(abs(j-i)==1);
                cout<<endl;
            }
        }
    }
    else if(a==1){
        cout<<"YES"<<endl;
        vector<vector<int>> g(n,vector<int>(n, 1)); 
        rep(i,n)rep(j,n){
            if(i<=n-b&&j<=n-b)g[i][j]=0;
        }
        rep(i,n)g[i][i]=0;
        rep(i,n){
            rep(j,n)cout<<g[i][j];
            cout<<endl;
        }
    }
    else if(b==1){
        cout<<"YES"<<endl;
        vector<vector<int>> g(n,vector<int>(n, 0)); 
        rep(i,n)rep(j,n){
            if(i<=n-a&&j<=n-a)g[i][j]=1;
        }
        rep(i,n)g[i][i]=0;
        rep(i,n){
            rep(j,n)cout<<g[i][j];
            cout<<endl;
        }
    }
    return 0;
}