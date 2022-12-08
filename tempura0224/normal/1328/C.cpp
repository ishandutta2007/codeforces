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
        int n;
        cin>>n;
        string s;
        cin>>s;
        string x,y;
        bool diff = false;
        rep(i,n){
            if(!diff){
                if(s[i]=='2'){
                    x += '1';
                    y += '1';
                }
                if(s[i]=='0'){
                    x += '0';
                    y += '0';
                }
                if(s[i]=='1'){
                    x += '1';
                    y += '0';
                    diff = true;
                }
            }
            else {
                if(s[i]=='2'){
                    x += '0';
                    y += '2';
                }
                if(s[i]=='0'){
                    x += '0';
                    y += '0';
                }
                if(s[i]=='1'){
                    x += '0';
                    y += '1';
                }
            }
        }
        cout<<x<<endl;
        cout<<y<<endl;

    }
    return 0;
}