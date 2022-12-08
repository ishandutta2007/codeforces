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

int sum[1234567],pre[1234567],suf[1234567];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    rep(i,n){
        if(s[i]=='(')++sum[i+1];
        else --sum[i+1];
    }
    rep(i,n)sum[i+1]+=sum[i];
    suf[n+1]=inf;
    rep(i,n)pre[i+1]=min(pre[i],sum[i+1]);
    rep(i,n)suf[n-i]=min(suf[n-i+1],sum[n-i]);
    int ans=0;
    if(sum[n]==2){
        rep(i,n){
            if(pre[i]>=0&&suf[i+1]>=2&&s[i]=='(')++ans;
        }
    }
    else if(sum[n]==-2){
        rep(i,n)if(pre[i]>=0&&suf[i+1]>=-2&&s[i]==')')++ans;
    }
    cout<<ans<<endl;
    return 0;
}