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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool did = false;
        rep(i,10){
            int x = 0, y = i;
            bool ok = true;
            rep(j,n){
                if(s[j]-'0'>=y){
                    y=s[j]-'0';
                }
                else if(s[j]-'0'<=i&&s[j]-'0'>=x){
                    x=s[j]-'0';
                }
                else ok=false;
            }
            if(ok){
                x = 0, y = i;
                rep(j,n){
                    if(s[j]-'0'>=y){
                        y=s[j]-'0';
                        cout<<2;
                    }
                    else if(s[j]-'0'<=i&&s[j]-'0'>=x){
                        x=s[j]-'0';
                        cout<<1;
                    }
                }
                cout<<endl;
                did = true;
                break;
            }
        }
        if(!did)cout<<"-"<<endl;
    }
    return 0;
}