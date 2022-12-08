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
        string s[n];
        rep(i,n)cin>>s[i];
        rep(i,n){
            rep(j,m){
                if(j%3==0)s[i][j]='X';
            }
        }
        rep(j,m-1){
            if(j%3==1){
                bool ok=false;
                rep(i,n){
                    if(!ok&&s[i][j]=='X'){
                        s[i][j+1]='X';
                        ok=true;
                    }
                }
                rep(i,n){
                    if(!ok&&s[i][j+1]=='X'){
                        s[i][j]='X';
                        ok=true;
                    }
                }
                if(!ok)s[n-1][j]=s[n-1][j+1]='X';
            }
        }
        if(m%3==0){
            bool ok=true;
            rep(i,n){
                if(s[i][m-1]=='X')s[i][m-2]='X';
            }
        }
        rep(i,n)cout<<s[i]<<endl;
        cout<<endl;
    }
    return 0;
}