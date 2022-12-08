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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int id1=0,id0=0;
    rep(i,n){
        if(s[i]=='0'){
            cout<<"1 "<<id0+1<<endl;
            ++id0;
            id0%=4;
        }
        else {
            if(id1==0)cout<<"3 1"<<endl;
            else if(id1==1)cout<<"3 3"<<endl;
            else if(id1==2)cout<<"4 1"<<endl;
            else if(id1==3)cout<<"4 3"<<endl;
            ++id1;
            id1%=4;
        }
    }
    return 0;
}