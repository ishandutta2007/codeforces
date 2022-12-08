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


int cnt[31];
int main(){
    int n,k;
    cin>>n>>k;
    if(n<k||__builtin_popcount(n)>k){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    rep(i,30){
        if(n&(1<<i)){
            ++cnt[i];
            --k;
        }
    }
    int idx=30;
    while(k>0){
        while(cnt[idx]==0)--idx;
        cnt[idx-1]+=2;
        --cnt[idx];
        --k;
    }
    rep(i,30){
        rep(j,cnt[i])printf("%d ",1<<i);
    }
    return 0;
}