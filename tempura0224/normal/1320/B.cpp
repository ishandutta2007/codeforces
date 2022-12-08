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
const ll mod[]={1000000000039, 1000000000061, 1000000000063};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        --x;--y;
        v[y].push_back(x);
    }
    int k;cin>>k;
    vector<int> a(k);
    rep(i,k){
        cin>>a[i];--a[i];
    }
    vector<ll> dist(n,inf);
    vector<vector<ll>> num(n,vector<ll>(3));
    dist[a[k-1]]=0;
    rep(j,3)num[a[k-1]][j]=1;
    queue<int> q;
    q.push(a[k-1]);
    while(q.size()){
        int c = q.front();q.pop();
        for(auto to:v[c]){
            if(dist[to]==inf){
                dist[to]=dist[c]+1;
                rep(j,3)num[to][j]=num[c][j];
                q.push(to);
            }
            else if(dist[to]==dist[c]+1){
                rep(j,3){
                    num[to][j]+=num[c][j];
                    if(num[to][j]>=mod[j])num[to][j]-=mod[j];
                }
            }
        }
    }
    int ans0 = 0, ans1= 0;
    rep(i,k-1){
        if(dist[a[i]]<dist[a[i+1]]+1){
            ++ans0;++ans1;
        }
        else if(dist[a[i]]==dist[a[i+1]]+1){
            bool ok=true;
            rep(j,3)if(num[a[i]][j]!=num[a[i+1]][j])ok=false;
            if(!ok)++ans1;
        }
    }
    cout<<ans0<<" "<<ans1<<endl;
    return 0;
}