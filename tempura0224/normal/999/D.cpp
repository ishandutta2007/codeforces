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

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],r[m];
    rep(i,m)r[i]=0;
    rep(i,n){
        cin>>a[i];
        r[a[i]%m]++;
    }
    queue<int> v[m];
    queue<int> q;
    rep(i,m){
        if(r[i]>n/m){
            int x=r[i]-n/m;
            rep(j,x)q.push(i);
            r[i]=n/m;
        }
        while(r[i]<n/m){
            if(q.empty())break;
            int x=q.front();
            q.pop();
            v[x].push(i);
            r[i]++;
        }
    }
    rep(i,m){
        if(r[i]>n/m){
            int x=r[i]-n/m;
            rep(j,x)q.push(i);
            r[i]=n/m;
        }
        while(r[i]<n/m){
            if(q.empty())break;
            int x=q.front();
            q.pop();
            v[x].push(i);
            r[i]++;
        }
    }
    ll ans=0;
    rep(i,n){
        int k=a[i]%m;
        if(!v[k].empty()){
            int x=v[k].front();
            v[k].pop();
            int cnt=(x-k+m)%m;
            a[i]+=cnt;
            ans+=cnt;
        }
    }
    cout<<ans<<endl;
    rep(i,n)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}