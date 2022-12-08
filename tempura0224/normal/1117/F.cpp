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

bitset<26> adj[1<<17][26],ok[26];
bool dp[1<<17];
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    rep(i,m)rep(j,m){
        int x;cin>>x;
        ok[i][j]=x;
    }
    rep(i,m){
        char cur='a'+i;
        rep(aaa,2){
            int mask=0;
            bool used=false;
            rep(j,n){
                int ch = s[j]-'a';
                if(ch!=i){
                    if(!used)continue;
                    if((mask>>ch)&1)continue;
                    adj[mask][i][ch]=1;
                    mask+=(1<<ch);
                }
                else {
                    if(used)adj[mask][i][i]=1;
                    used=true;
                    mask=0;
                }
            }
        reverse(s.begin(),s.end());
        }
    }
    int all=1<<m;
    rep(i,26){
        rep(j,m)rep(k,all){
            if((1<<j)&k)adj[k][i]|=adj[k^(1<<j)][i];
        }
    }
    rep(i,all)rep(j,m)rep(k,m){
        if((1<<j)&i)adj[i][k][j]=0;
    }

    dp[0]=1;
    rep(i,all){
        bool can=false;
        rep(j,m){
            if(((1<<j)&i)==0)continue;
            if(!dp[i^(1<<j)])continue;
            can=true;
        }
        if(!can)continue;
        rep(k,m){
            if((1<<k)&i)continue;
            bitset<26> res=adj[i][k];
            if((res&ok[k])!=res)can=false;
        }
        dp[i]=can;
        
    }
    int ans=n;
    vector<int> cnt(m);
    rep(i,n){
        cnt[s[i]-'a']++;
    }
    rep(i,all){
        if(!dp[i])continue;
        int ret=0;
        rep(j,m)if(((i>>j)&1)==0)ret+=cnt[j];
        ans=min(ans,ret);
    }
    cout<<ans<<endl;
    return 0;
}