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

ll cnt[101010];
int main(){
    ll n,s;
    cin>>n>>s;
    if(2*n-1>s||s>n*(n+1)/2){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;
    ll ok=n-1,ng=0;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        ll ret=0;
        ll m=n;
        ll pos=1;
        ll c=1;
        while(m){
            ret+=c*min(pos,m);
            m-=min(pos,m);
            pos*=mid;
            ++c;
        }
        if(ret<=s)ok=mid;
        else ng=mid;
    }
    ll sum=0;
    priority_queue<int> que;
    rep(i,n){
        cnt[i+1]=1;
        sum+=i+1;
        que.push(i+1);
    }
    sum-=s;
    while(sum){
        int x=que.top();que.pop();
        int ret=max(2LL,x-sum);
        while(cnt[ret]==cnt[ret-1]*ok)++ret;
        ++cnt[ret];
        --cnt[x];
        sum-=(x-ret);        
        que.push(ret);
    }
    int pos=1;
    rep(i,n){
        rep(j,cnt[i+2]){
            cout<<pos+j%cnt[i+1]<<" ";
        }
        pos+=cnt[i+1];
    }
    return 0;
}