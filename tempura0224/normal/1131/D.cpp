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


struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
};
int main(){
    int n,m;
    cin>>n>>m;
    string s[n];
    rep(i,n)cin>>s[i];
    vector<int> v[n+m];
    vector<int> cnt(n+m);
    UnionFind uf(n+m);
    rep(i,n)rep(j,m){
        if(s[i][j]=='=')uf.unite(i,j+n);
    }
    rep(i,n)rep(j,m){
        if(s[i][j]=='<'){
            v[uf.find(i)].push_back(uf.find(n+j));
            ++cnt[uf.find(n+j)];
        }
        if(s[i][j]=='>'){
            v[uf.find(n+j)].push_back(uf.find(i));
            ++cnt[uf.find(i)];
        }
    }
    vector<int> ans(n+m);
    vector<int> used(n+m);
    queue<int> que;
    rep(i,n+m){
        if(!cnt[i]){
            ans[i]=1;
            used[i]=true;
            que.push(i);
        }
    }
    while(que.size()){
        int x=que.front();
        que.pop();
        for(auto to : v[x]){
            if(used[to])continue;
            ans[to]=max(ans[x]+1,ans[to]);
            if(--cnt[to]==0){
                used[to]=true;
                que.push(to);
            }
        }
    }
    rep(i,n+m){
        if(!used[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    rep(i,n)rep(j,m){
        if(s[i][j]=='='){
            if(ans[uf.find(i)]!=ans[uf.find(n+j)]){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(s[i][j]=='<'){
            if(ans[uf.find(i)]>=ans[uf.find(n+j)]){
                cout<<"No"<<endl;
                return 0;
            }
        }
        if(s[i][j]=='>'){
            if(ans[uf.find(i)]<=ans[uf.find(n+j)]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    rep(i,n){
        cout<<ans[uf.find(i)]<<" ";
    }
    cout<<endl;
    rep(i,m){
        cout<<ans[uf.find(n+i)]<<" ";
    }
    return 0;
}