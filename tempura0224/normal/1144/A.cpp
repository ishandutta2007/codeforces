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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


bool solve(){
    string s;
    cin>>s;
    vector<int> cnt(26);
    rep(i,s.size())cnt[s[i]-'a']++;
    int step=0;
    rep(i,26){
        if(cnt[i]>1)return false;
        else if(step==0&&cnt[i]==1)step=1;
        else if(step==1&&cnt[i]==0)step=2;
        else if(step==2&&cnt[i]==1)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    rep(i,n){
        if(solve())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}