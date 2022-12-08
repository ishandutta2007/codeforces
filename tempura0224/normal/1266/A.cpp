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
    int q;
    cin>>q;
    rep(i,q){
        string s;
        cin>>s;
        int sum=0, zero=0, even=0;
        int n=s.size();
        rep(i,n){
            int x=s[i]-'0';
            if(x==0)zero++;
            else if(x%2==0)even++;
            sum += x;
        }
        if(sum%3!=0){
            cout<<"cyan"<<endl;
        }
        else {
            if(zero>=2){
                cout<<"red"<<endl;
            }
            else if(zero==1&&even>0){
                cout<<"red"<<endl;
            }
            else cout<<"cyan"<<endl;
        }
    }
    return 0;
}