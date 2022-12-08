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
    int n;
    cin>>n;
    cout<<"10 0"<<endl;
    string s;
    cin>>s;
    if(n==1){
        cout<<"1 1 2 1"<<endl;
        return 0;
    }
    --n;
    ll left=0,right=1<<29;
    int st=10;
    bool same=true;
    while(1){
        if(n==0)break;
        cout<<st<<" "<<right<<endl;
        string t;cin>>t;
        n--;
        if(s==t){
            st+=2;
        }
        else{
            same=false;
            break;
        }
    }
    if(n==0&&same){
        cout<<"100 0 100 1"<<endl;
    }
    int mid=(left+right)/2;
    while(n>0){
        cout<<st<<" "<<mid<<endl;
        string t;cin>>t;
        if(s==t)left=mid;
        else right=mid;
        mid=(left+right)/2;
        --n;
    }
    cout<<st-1<<" "<<(1<<29)<<" "<<st<<" "<<mid<<endl;
    return 0;
}