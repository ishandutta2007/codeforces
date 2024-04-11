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
        int n;;
        cin>>n;
        string s[n];
        rep(i,n)cin>>s[i];
        int sum=0;
        rep(i,n)rep(j,n){
            if(s[i][j]=='O'||s[i][j]=='X')++sum;
        }
        vector<int> cnt(3);
        rep(i,n)rep(j,n){
            if(s[i][j]=='X')cnt[(i+j)%3]++;
            if(s[i][j]=='O')cnt[(i+j+1)%3]++;
        }
        vector<int> cnt2(3);
        rep(i,n)rep(j,n){
            if(s[i][j]=='X')cnt2[(i+j+1)%3]++;
            if(s[i][j]=='O')cnt2[(i+j)%3]++;
        }
        bool ok=false;
        rep(t,3){
            if(!ok&&3*cnt[t]<=sum){
                ok=true;
                rep(i,n)rep(j,n){
                    if(s[i][j]=='X'&&(i+j)%3==t)s[i][j]='O';
                    else if(s[i][j]=='O'&&(i+j+1)%3==t)s[i][j]='X';
                }
            }
        }
        rep(t,3){
            if(!ok&&3*cnt2[t]<=sum){
                ok=true;
                rep(i,n)rep(j,n){
                    if(s[i][j]=='X'&&(i+j+1)%3==t)s[i][j]='O';
                    else if(s[i][j]=='O'&&(i+j)%3==t)s[i][j]='X';
                }
            }
        }
        assert(ok);
        rep(i,n)cout<<s[i]<<endl;
    }
    return 0;
}