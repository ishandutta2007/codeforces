#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60;
const ll mod=1e9+7;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1};

int cnt[10];
ll comb[20][20];
ll dfs(int n,int sum){
    if(n==-1)return 1;
    if(cnt[n]==0)return dfs(n-1,sum);
    ll ret=0;
    rep(i,cnt[n]){
        ll res=dfs(n-1,sum+i+1);
        res*=comb[sum+i+1][sum];
        ret+=res;
    }
    return ret;
}
ll dfs2(int n,int sum){
    if(n==0)return 1;
    if(cnt[n]==0)return dfs2(n-1,sum);
    ll ret=0;
    rep(i,cnt[n]){
        ll res=dfs2(n-1,sum+i+1);
        res*=comb[sum+i+1][sum];
        ret+=res;
    }
    return ret;
}
int main(){
    ll n;
    cin>>n;
    while(n>0){
        cnt[n%10]++;
        n/=10;
    }
    rep(i,20){
        comb[i][0]=comb[i][i]=1;
    }
    rep(i,20){
        if(i<2)continue;
        rep(j,20){
            if(j>0&&j<i)comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
        }
    }
    ll ans=dfs(9,0);
    if(cnt[0]>0){
        cnt[0]--;
        ans-=dfs(9,0);
        if(cnt[0]>0)ans-=dfs2(9,0);
    }
    cout<<ans<<endl;
    return 0;
}